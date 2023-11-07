class File {
 public:
  virtual ~File() = default;
  virtual bool isDirectory() const = 0;
  virtual vector<string> list() const = 0;
};

class RegularFile : public File {
 public:
  explicit RegularFile(const string &file_name) : file_name_(file_name) {}

  ~RegularFile() override = default;

  bool isDirectory() const override { return false; }

  vector<string> list() const override { return {file_name_}; }

  void append(const string &new_content) { content_.append(new_content); }

  const string &get_content() const { return content_; }

 private:
  const string file_name_;
  string content_;
};

class Directory : public File {
 public:
  ~Directory() override = default;

  bool isDirectory() const override { return true; }

  vector<string> list() const override {
    vector<string> results;
    results.reserve(files_.size());
    for (const auto &[file_name, _] : files_) {
      results.push_back(file_name);
    }
    return results;
  }

  File *getFile(const string &file_name) const {
    auto it = files_.find(file_name);
    if (it == files_.end()) {
      return nullptr;
    }
    return it->second.get();
  }

  void addFile(const string &file_name, unique_ptr<File> file) {
    files_.emplace(file_name, move(file));
  }

 private:
  map<string, unique_ptr<File>> files_;
};

class FileSystem {
 public:
  FileSystem() = default;

  vector<string> ls(string path) { return getFile(path, false)->list(); }

  void mkdir(string path) { (void)getFile(path, true); }

  void addContentToFile(string filePath, string content) {
    auto *file = dynamic_cast<RegularFile *>(getFile(filePath, false));
    assert(file != nullptr);
    file->append(content);
  }

  string readContentFromFile(string filePath) {
    auto *file = dynamic_cast<RegularFile *>(getFile(filePath, false));
    assert(file != nullptr);
    return file->get_content();
  }

 private:
  File *getFile(const string &path, bool is_directory) {
    Directory *directory = &root_;
    for (int i = 1, j = 1; j <= path.size(); ++j) {
      if (j < path.size() && path[j] != '/') {
        continue;
      }
      if (i < j) {
        const string file_name = path.substr(i, j - i);
        File *file = directory->getFile(file_name);
        if (file == nullptr) {
          unique_ptr<File> new_file;
          if (!is_directory && j == path.size()) {
            new_file = make_unique<RegularFile>(file_name);
          } else {
            new_file = make_unique<Directory>();
          }
          file = new_file.get();
          directory->addFile(file_name, move(new_file));
        }
        if (!is_directory && j == path.size()) {
          return file;
        }
        directory = dynamic_cast<Directory *>(file);
      }
      i = j + 1;
    }
    return directory;
  }

  Directory root_;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
