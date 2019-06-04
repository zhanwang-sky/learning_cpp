#ifndef _MESSAGE_H
#define _MESSAGE_H

#include <string>
#include <set>

class Folder;

class Message {
    friend class Folder;
    friend void swap(Message&, Message&);
public:
    explicit Message(const std::string &str = "");
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
private:
    std::string contents;
    std::set<Folder*> folders;
    void add_to_folders(const Message&);
    void remove_from_folders();
};

class Folder {
public:
    void addMsg(Message*);
    void remMsg(Message*);
};

#endif // _MESSAGE_H
