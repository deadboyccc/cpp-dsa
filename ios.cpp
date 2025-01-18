#include "pch.h"
// create a define to use for v.begin(),v.end() in one word

void foo(std::function<void(int)> l) {
  // Calls the lambda function with 5 and 10
  l(5);
  l(10);
}
void bar(void (*l)(int)) {
  l(5);
  l(10);
}
class Factorial_Func {
  // The function object will be called by the range-based for loop
 public:
  int operator()(int x) const {
    int result = 1;
    for (int i = 1; i <= x; ++i) {
      result *= i;
    }
    return result;
  }
};
void print_if(const std::vector<int> &v, std::function<bool(int)> l) {
  for (const auto &i : v) {
    if (l(i)) {
      std::cout << i << " ";
    }
  }
}

void pairing(const std::pair<int, int> &p,
             std::function<bool(std::pair<int, int>)> l) {
  std::cout << "First: " << p.first << " Second: " << p.second << std::endl;
  if (l(p)) {
    std::cout << "Pair is valid" << std::endl;
  } else {
    std::cout << "Pair is invalid" << std::endl;
  }
}
class Player {
 public:
  enum class Direction { South, North, East, West };
  enum class PlayerMode { Human, AI };
  std::string name;
  Direction dir;
  PlayerMode mod;
  Player(std::string n, Direction d, PlayerMode m) : name(n), dir(d), mod(m) {}
  Player(const Player &other)
      : name(other.name), dir(other.dir), mod(other.mod) {}
  Player &operator=(const Player &other) {
    name = other.name;
    dir = other.dir;
    mod = other.mod;
    return *this;
  }

  ~Player() {}
  friend std::ostream &operator<<(std::ostream &out, const Player &p) {
    out << "Name: " << p.name << ", Direction: " << static_cast<int>(p.dir)
        << ", Mode: " << static_cast<int>(p.mod) << std::endl;
    return out;
  }
};

int main() {
  Player p1{"Ahmed", Player::Direction::East, Player::PlayerMode::Human};
  std::cout << p1;
  std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // std::sort(v.begin(), v.end(), std::greater<int>());

  // auto result = std::any_of(v.begin(), v.end(), [](int item)
  //                           { return item %
  // for (auto item : v)
  // {
  //     std::cout << result_direction(item) << std::endl;
  // }
  // std::cout << std::endl
  //           << std::boolalpha << result;
  // std::cout << std::resetiosflags(std::ios::boolalpha);
  // std::cout << (1 == 1) << st::endl;
  // std::vector<int> scores{92, 81, 84, 71};
  // std::pair<int, int> range{80, 100};
  // auto result = std::all_of(scores.begin(), scores.end(), [range](int score)
  //                           { return score >= range.first && score <=
  //                           range.second; });
  // std::cout << std::boolalpha << result << std::endl;
  // using ipair = std::pair<int, int>;
  // std::vector<ipair> v{};
  // v.emplace_back(std::make_pair(1, 2));
  // v.emplace_back(std::make_pair(3, 4));
  // v.emplace_back(std::make_pair(5, 6));
  // v.emplace_back(std::make_pair(7, 8));
  // v.emplace_back(std::make_pair(9, 10));
  // std::sort(v.begin(), v.end(), [](const auto &pair, const auto &pair2)
  //           { return pair.second < pair2.second; });

  // int a{1000};
  // int b{-2};
  // std::for_each(v.begin(), v.end(), [&a, &b](auto &pair)
  //               { pair.first += a;
  //               pair.second += b; });

  // for (auto item : v)
  // {
  //     std::cout << "First: " << item.first << " Second: " << item.second <<
  //     std::endl;
  // }
  // pairing(std::make_pair(10, 1), [](std::pair<int, int> p)
  //         { return p.first < p.second; });

  // std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // print_if(v, [](int x)
  //          { return x % 2 == 0; });
  // std::cout << std::endl;

  // std::function<void(void)> l = []()
  // { std::cout << "hi" << std::endl; };
  // l();

  // foo([](int x)
  //     { std::cout << x * x << std::endl; });
  // bar([](int x)
  //     { std::cout << x * x << std::endl; });
  // int test{0};
  // int test2{2};
  // std::cout << "Enter a number: ";
  // std::cin >> test;
  // std::cin.clear();
  // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  // std::cin >> test2;
  // std::cout << "first: " << test << " Second: " << test2 << std::endl;

  // auto l = []()
  // { std::cout << "hello world!" << std::endl; };
  // l();
  // l();
  // std::vector<int> a{1, 2, 3, 4, 5};
  // std::for_each(a.begin(), a.end(), [](int &x)
  //               { std::cout << &x << " "; });
  // std::cout << std::endl;
  // for (auto item : a)
  // {
  //     std::cout << item << " ";
  // }
  // 5 * 4 =20 *3 = 60 *2 = 120
  //   std::map<int, int> m;
  //  m.emplace(std::make_pair<int, int>(10, 10));
  //  m.emplace(std::make_pair<int, int>(20, 20));
  //  m.emplace(std::make_pair<int, int>(30, 30));
  //  m.emplace(std::make_pair<int, int>(40, 40));
  //  m.emplace(std::make_pair<int, int>(1, 1));

  // for (auto item : m)
  // {
  //     std::cout << "{" << item.first << "," << item.second << "}" <<
  //     std::endl;
  // }

  // std::vector<int> v{1, 2, 3, 4, 5};
  // std::forward_list<int> l{1, 2, 3, 4, 5};
  // std::vector<std::pair<std::string, std::string>> pairs;
  // pairs.emplace_back("hello", "bye");

  // auto it = l.begin();
  // std::advance(it, 2);
  // for (auto iter = it; iter != l.end(); iter++)
  // {
  //     std::cout << *iter << " ";
  // }

  // std::cout << std::endl;
  // std::vector<int> v2{10, 100, 1000, 10000, 100000};
  // std::vector<int> v3;
  // std::transform(v.begin(), v.end(), v2.begin(), v2.begin(),
  // std::multiplies<int>()); for (auto item : v2)
  // {
  //     std::cout << item << " ";
  // }

  //               { std::cout << item << " "; });
  // std::sort(v.begin(), v.end());
  // std::replace(v.begin(), v.end(), 10, 1000000);

  // Square square;
  // std::for_each(v.begin(), v.end(), square);

  // auto it = std::find(v.begin(), v.end(), 4);

  // v.insert(it, 10);
  // for (auto &item : v)
  // {
  //     std::cout << item << " ";
  // }
  // std::cout << std::endl;
  // std::cout << std::setfill('=') << std::setw(10) << "" << std::endl;
  // std::priority_queue<int, std::vector<int>, std::greater<int>> pqLess;
  // pqLess.emplace(10);
  // pqLess.emplace(20);
  // pqLess.emplace(5);
  // std::cout << "Priority Queue (Less): ";
  // while (!pqLess.empty())
  // {
  //     std::cout << pqLess.top() << " ";
  //     pqLess.pop();
  // }

  // std::string s;
  // std::ostringstream out_put{s};
  // out_put << "Hello, World!" << std::endl;
  // std::cout << out_put.str() << std::endl;
  // std::string s2{"Bye World I am crazy"};
  // std::istringstream in_put{s2};
  // std::string s3;
  // int i{};
  // while (in_put >> s3)
  // {
  //     std::cout << s3 << std::endl;
  //     std::cout << ++i << std::endl;
  // }

  // std::vector v3{1, 2, 3, 3, 4, 5};
  // auto wow = std::count_if(v3.begin(), v3.end(), [](int x)
  //                          { return x > 3; });
  // std::cout << wow << std::endl;
  // std::vector v2(6, 100);
  // std::vector<int> v4;
  // std::transform(v3.begin(), v3.end(), v2.begin(), std::back_inserter(v4),
  // [](int x, int y)
  //                { return x * y; });

  // for (auto item : v4)
  // {
  //     std::cout << item << " ";
  // }
  // std::cout << std::endl;
  // std::cout << v2.max_size() << std::endl;
  // auto j = std::numeric_limits<size_t>::max();
  // std::cout << j << std::endl;

  // std::array<int, 10> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // for (auto it = arr.crbegin(); it != arr.crend(); it++)
  // {
  //     std::cout << *it << " ";
  // }
  // std::tuple<int, double, char> t{12, 12.888, 'B'};
  // std::cout << std::get<0>(t) << std::endl;
  // std::pair<int, double> p{12, 12.321};
  // std::cout << "Pair: (" << p.first << ", " << p.second << ")\n";

  // void (*hello)(int, double) = print_hello;

  // hello(9, 1.2);
  // print_hello(2, 3.2);
  // auto f = [](int l, int m)
  // { return l + m; };
  // std::cout << f(20, 30);
  // std::vector<int> v{5, 3, 2};
  // std::sort(v.begin(), v.end());

  // int sum = std::accumulate(v.begin(), v.end(), 0);

  // std::cout << "Sum: " << sum << std::endl;
  // std::reverse(v.begin(), v.end());
  // std::cout << " Reversed Sorted Vector: ";
  // for (auto item : v)
  // {
  //     std::cout << item << " ";
  // }
  // std::ofstream output_file{
  //     "../ios_backup.txt",
  // };
  // std::ifstream input_file{"../ios.txt"};
  // if (!input_file || !output_file)
  // {
  //     std::cerr << "Error opening the file";
  //     return 1;
  // }
  // std::string line;
  // int a{0};
  // while (std::getline(input_file, line))

  // {
  //     if (line.empty())
  //     {
  //         output_file << std::endl;
  //         continue;
  //     }
  //     a++;
  //     output_file << std::left << std::setw(5) << std::left << a << line <<
  //     std::endl;
  // }
  // output_file.close();
  // input_file.close();
  // std::string filename = "../ios.txt";
  // std::ifstream in_file(filename);
  // if (!in_file)
  // {
  //     std::cerr << "Error reading the file";
  //     return 1;
  // }
  // std::cout << "Student" << std::setw(20) << "Grade" << std::endl;
  // std::cout << std::setw(27) << std::setfill('-') << "" << std::endl;
  // std::cout << std::setfill(' ');

  // std::string name{}, grade{};
  // while (!in_file.eof())
  // {
  //     in_file >> grade >> name;
  //     std::cout << std::setw(22) << std::left << name;
  //     int count{0};
  //     for (auto i = 0; i < grade.size(); i++)
  //     {
  //         if (i == 0 && grade[i] == 'A')
  //             count++;
  //         else if (i == 1 && grade[i] == 'B')
  //             count++;
  //         else if (i == 2 && grade[i] == 'C')
  //             count++;
  //         else if (i == 3 && grade[i] == 'D')
  //             count++;
  //         else if (i == 4 && grade[i] == 'E')
  //             count++;
  //     }
  //     std::cout << std::setw(10) << std::left << count << std::endl;
  // }
  // std::cout << std::setw(27) << std::setfill('-') << "" << std::endl;
}
