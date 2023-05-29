#include <iostream>
#define S_SIZE 
using namespace std;


class s_record 
{
    public:
    string s_id;    // 학번 (Key)
    string name;    // 성명
    double  score;  // 점수
    s_record();
    s_record(string s1, string s2, double n);
};



void show_thelist(s_record a[], int n);

void heap_sort(s_record a[], int n);

void insertion_sort(s_record a[], int n);

void adjust(s_record a[], int root, int n);

int main()

{

      s_record s_list[12] = { {"21900013", "Kim ", 6.5}, {"21900136", "Lee ", 8.8 }, {"21900333", "Park", 9.2 },

                                  { "21800442", "Choi", 7.1}, {"21900375", "Ryu ", 5.4  }, {"21700248", "Cho ", 6.3 },

                  { "21700302", "Jung", 8.3}, {"21800255", "Han ", 6.9  }, {"21800369", "Kang", 6.3 },

                  { "21900401", "Yang", 9.1}, {"21800123", "Moon", 8.1  }, {"21700678", "Seo ", 7.9 } };

      int    n = 12;

    //   insertion_sort(s_list, n);

    //   bubble_sort(s_list, n);

    //   selection_sort(s_list, n);

    //   quick_sort(s_list, 0, n-1);

    heap_sort(s_list, n);

    //   merge_sort(s_list, n); 

      cout << "< The result of the sorting >" << endl;

      show_thelist(s_list, n);

      return 0;

}

s_record::s_record()
{
    s_id = "";
    name = "";
    score = 0;
}

s_record::s_record(string s1, string s2, double n)
{
    s_id = s1;
    name = s2;
    score = n;
}

void insertion_sort(s_record a[], int n)
{
    for (int j = 1; j < n; j++) 
    {
        s_record temp = a[j];
        int k = j-1;
        while ((k >= 0)&&(a[k].s_id > temp.s_id)) 
        {
            a[k + 1] = a[k];
            k--;
        }
        a[k + 1] = temp;
    }
}


void show_thelist(s_record a[], int n)
{
    for (int i = 0;i < n; i++)
    {
        cout << a[i].s_id << "  :  ";cout << a[i].name << "  :  ";
        cout << a[i].score << endl;
    }
}


void heap_sort(s_record a[], int n)
{
    int i;
    s_record b[n+1], temp;

    for (i = 0; i < n; i++) {
        b[i + 1] = a[i];
    }

    for (i = n / 2; i > 0; i--) {
        adjust(b, i, n);
    }

    for (i = n; i > 1; i--) {
        temp = b[1];
        b[1] = b[i];
        b[i] = temp;
        adjust(b, 1, i - 1);
    }

    for (i = 0; i < n; i++) {
        a[i] = b[i + 1];
    }
}



void adjust(s_record a[], int root, int n)
{
    int child;
    s_record temp = a[root];

    while (root * 2 <= n)
    {
        child = root * 2;
        if (child < n && a[child].score < a[child + 1].score)
            child++;
        if (temp.score >= a[child].score)
            break;
        a[root] = a[child];
        root = child;
    }
    a[root] = temp;
}
