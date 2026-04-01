#include <string>

class Student {
  private:
    int _age;
    int _id_card;
    std::string _name;
    std::string _gender;
    std::string _email;
    std::string _major;
    std::string _college;

    int generate_id_card(const std::string &name);

  public:
    Student();
    Student(std::string name);
    Student(int age, std::string name);
    Student(const Student &rhs);
    ~Student();

    void set_age(int age);
    void set_name(const std::string &name);
    void set_gender(const std::string &gender);
    void set_email(const std::string &email);
    void set_major(const std::string &major);
    void set_college(const std::string &college);

    int get_age() const;
    int get_id_card() const;

    std::string get_name() const;
    std::string get_email() const;
    std::string get_major() const;
    std::string get_college() const;
};

#include "class.cpp"
