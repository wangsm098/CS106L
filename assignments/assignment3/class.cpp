Student::Student() : _age(0), _id_card(0), _name(""), _gender(""), _email(""), _major(""), _college("") {}

Student::Student(std::string name) : _age(0), _id_card(generate_id_card(name)), _name(name), _gender(""), _email(""), _major(""), _college("") {}

Student::Student(int age, std::string name) : _age(age), _id_card(generate_id_card(name)), _name(name), _gender(""), _email(""), _major(""), _college("") {}

Student::Student(const Student& rhs) : _age(rhs._age), _id_card(rhs._id_card), _name(rhs._name), _gender(rhs._gender), _email(rhs._email), _major(rhs._major), _college(rhs._college) {}

Student::~Student() {}

int Student::generate_id_card(const std::string& name) {
    unsigned int id = 0, P = 1331;
    for (char ch : name) {
        id = id * P + ch;
    }
    return static_cast<int>(id);
}

void Student::set_age(int age) {
    this->_age = age; 
}

void Student::set_name(const std::string& name) {
    this->_name = name;
}

void Student::set_gender(const std::string& gender) {
    this->_gender = gender;
}

void Student::set_email(const std::string& email) {
    this->_email = email;
}

void Student::set_major(const std::string& major) {
    this->_major = major;
}

void Student::set_college(const std::string& college) {
    this->_college = college;
}

int Student::get_age() const {
    return _age;
}

int Student::get_id_card() const {
    return _id_card;
}

std::string Student::get_name() const {
    return _name;
}

std::string Student::get_email() const {
    return _email;
}

std::string Student::get_major() const {
    return _major;
}

std::string Student::get_college() const {
    return _college;
}
