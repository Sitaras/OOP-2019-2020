using std::string;

const int n_of_themes=5;
const int n_of_creators=4;
const int n_of_titles=4;
const int n_of_texts=7;


const string themes[n_of_themes]{
  "Κανόνες και χρήσιμες πληροϕορίες", /* this thread always be created */
  "Συναρτησεις",
  "Κλασεις",
  "Δομες",
  "Δεικτες",
};

const string titles[n_of_titles]{
  "~Χωρίς Τιτλο~",
  "~Απαντηση~",
  "~Υποδειξη~",
  "~Ερωτηση~"
};

const string creators[n_of_creators]{
  "παναγιωτησ",
  "δημητρης",
  "μαρια",
  "ανεστης"
};

const string texts[n_of_texts]{
  "Δεν ξερω τι γινεται με την δυναμικη δεσμευση",
  "Μπορειτε να μου εξηγησετε την λειτουργια των δεικτων",
  "πως θα υλοποιησω κλασεις μεσα σε κλασεις",
  "Διαβασε σημειωσεις μαθηματος στις αντιστοιχες σελιδες",
  "Εκτελεσαι τα αντιστοιχα παραδειγματα που υπαρχουν στην σελιδα του μαθηματος",
  "Ξαναδιαβασε την εκφωνηση",
  "Περιεγραψε λιγο καλυτερο το προβλημα για να καταλαβω"
};

int th_number();
int pos_number();



class forum;
class thread;
class post;


struct date {
  int day;
  int month;
  int year;

  date();
};



class forum{
  private:
    string title;
    int threads;
    thread* th_array;


  public:

    forum(string);
    ~forum();

    string get_title() const;
    int get_threads() const;

    void printforum() const;

    void thread_select(string) const;
    void post_select(int) const;

};

class thread {
  private:
    string theme;
    string creator;
    date x;
    int numposts;
    post* po_array;


  public:

    thread();
    ~thread();


    int search_post(int) const;
    void printposts() const;

    date get_x() const;
    string get_theme() const;
    int get_numposts() const;
    string get_creator() const;
    post* get_po_array() const;

};

class post{
private:
  int id;
  date x;
  string title;
  string creator;
  string text;
  static int number;


public:

  post();
  ~post();

  static int get_num();

  int get_id() const;
  date get_x() const;
  string get_title() const;
  string get_creator() const;
  string get_text() const;


};
