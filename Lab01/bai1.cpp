#include <bits/stdc++.h>
#include <string>
using namespace std;

bool checkphone(string a)
{
    if(a.length() != 10) return false;
    for (int i = 0; i < a.length(); i++)
    {
        if(!(a[i] >= '0' && a[i] <= '9')) return false;
    }
    return true;
}

int counttime(string ftime, string etime)
{
    int starttime = 3600*((ftime[0] - '0')*10 + (ftime[1] - '0')) + 60*((ftime[3] - '0')*10 + (ftime[4] - '0')) + ((ftime[6]- '0')*10 + (ftime[7] - '0'));
    int endtime = 3600*((etime[0] - '0')*10 + (etime[1] - '0')) + 60*((etime[3] - '0')*10 + (etime[4] - '0')) + ((etime[6] - '0')*10 + (etime[7] - '0'));
    return endtime - starttime;
}

map <string, int> numberCalls, timeCall;

int main()
{
    // tang toc do nhap input
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string type;
    int totalcalls = 0;
    int incorrectPhone = 0;
    do
    {
        cin >> type;
        if (type == "#") continue;
        totalcalls = totalcalls + 1;
        string fnum, tnum, date, ftime, etime;
        cin >> fnum >> tnum >> date >> ftime >> etime;
        if(!checkphone(fnum) || !checkphone(tnum))
            incorrectPhone = incorrectPhone + 1;
        numberCalls[fnum]++;
        timeCall[fnum] += counttime(ftime, etime);
    } while(type != "#");

    do
    {
        cin >> type;
        if (type == "#") break;
        if (type == "?check_phone_number")
        {
            if(incorrectPhone == 0) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if (type == "?number_total_calls")
        {
        	cout << totalcalls << endl;
		}
        else if (type == "?number_calls_from")
        {
            string phone;
            cin >> phone;
            cout << numberCalls[phone] << endl;
        }
        else if (type == "?count_time_calls_from")
        {
            string phone;
            cin >> phone;
            cout << timeCall[phone] << endl;
        }
    } while (type != "#");
    return 0;
}