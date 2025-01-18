#include <iostream>
#include <intrin.h>
#include <string>
class strings
{
private:
    int length;
    char *str;

public:
    strings()
    {
        length = 0;
        str = nullptr;
    };

    strings(char *ptr)
    {
        length = strlen(ptr);
        str = new char[length + 1];
        strcpy(str, ptr);
    }
    ~strings()
    {
        delete[] str;  // Deallocate memory allocated for the string
        str = nullptr; // Reset the string pointer to null to prevent memory leaks
        length = 0;    // Reset the length to 0 to indicate an empty string
    };
    void display()
    {
        std::cout << str << std::endl;
        std::cout << "Length: " << length << std::endl;
    }
    void count()
    {
        int count = 0;
        int i = 0;
        while (str[i] != '\0')
        {
            i++;
            count++;
        }
        std::cout << "Number of characters: " << count << std::endl;
    }
    void ToLower()
    {
        for (int i = 0; str[i] != '\0'; i++)
        {
            str[i] += 32;
            std::cout << str[i] << std::endl;
        }
    }
};
//? This is elegant and optimal from character pointer aka array
// TODO char *S = character pointer and that is how u pass an array
// TODO or char s[] = same thing for the compiler, u pass by ref pointer

void perm(char *s, int l, int h)
{

    if (l == h)
    {
        std::cout << s << std::endl;
    }
    else
    {
        for (int i = l; i <= h; i++)
        {
            std::swap(s[l], s[i]);
            perm(s, l + 1, h);
            std::swap(s[l], s[i]);
        }
    }
}
//? This is elegant and optimal from string
void permString(std::string &s, int l, int h)
{

    if (l == h)
    {
        std::cout << s << std::endl;
    }
    else
    {
        for (int i = l; i <= h; i++)
        {
            std::swap(s[l], s[i]);
            permString(s, l + 1, h);
            std::swap(s[l], s[i]);
        }
    }
}
//? in my opinion void permutation is not elegant
void permutation(char *s, int k)
{
    static int a[10] = {0};
    static char res[10];
    static int c = 0;
    int i;
    if (s[k] == '\0')
    {
        res[k] = '\0';
        std::cout << res << std::endl;
        c++;
        std::cout << c << std::endl;
        return;
    }
    else
    {
        for (i = 0; s[i] != '\0'; i++)
            if (a[i] == 0)
            {
                a[i] = 1;
                res[k] = s[i];
                permutation(s, k + 1);
                a[i] = 0;
            }
    }
}
int main(int argc, char const *argv[])
{
    // char s[] = "ABC";
    // std::string test = "ABC";
    // char t[] = "DEF";
    // for (int i = 0; i < 3; i++)
    // {
    //     std::swap(s[i], t[i]);
    // }
    // permutation(s, 0);
    // perm(s,0,2);
    // permString(test,0,2);
    int a[5];
    return 0;
}
