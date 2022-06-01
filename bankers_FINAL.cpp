#include <bits/stdc++.h>
using namespace std;
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));

int main()
{
    // fastread();
    cout << "**************BANKER'S ALGO*******************" << endl;
    cout << "ENTER PROCESS: ";
    int process, resource;
    cin >> process;
    cout << "*********************************" << endl;
    cout << "ENTER RESOURCES ";
    cin >> resource;
    int allocated[process][resource], max_need[process][resource], need_mat[process][resource];
    int total[resource] = {0}, sum[resource] = {0}, free_mat[resource] = {0}, available[resource] = {0};
    cout << "*********************************" << endl;
    cout << "ENTER TOTAL RESOURCES " << endl;
    for (int i = 0; i < resource; i++)
    {
        cout << "RESOURCE " << char('A' + i) << ": ";
        cin >> total[i];
    }
    cout << "ENTER ALLOCATED RESOURCES: " << endl;
    cout << "   ";
    for (int i = 0; i < resource; i++)
        cout << char('A' + i) << " ";
    cout << endl;
    for (int i = 0; i < process; i++)
    {
        cout << "P" << i << " ";
        for (int j = 0; j < resource; j++)
        {
            cin >> allocated[i][j];
        }
    }

    cout << "*********************************" << endl;

    cout << "ENTER MAX NEED OF RESOURCES FOR PROCESS" << endl;
    cout << "   ";
    for (int i = 0; i < resource; i++)
        cout << char('A' + i) << " ";
    cout << endl;
    for (int i = 0; i < process; i++)
    {
        cout << "P" << i << " ";
        for (int j = 0; j < resource; j++)
        {
            cin >> max_need[i][j];
        }
    }
    for (int i = 0; i < process; i++)
    {
        for (int j = 0; j < resource; j++)
            need_mat[i][j] = max_need[i][j] - allocated[i][j];
    }
    cout << "*********************************" << endl;
    cout << "NEED MATRIX: " << endl;
    for (int i = 0; i < resource; i++)
        cout << char('A' + i) << " ";
    cout << endl;
    for (int i = 0; i < process; i++)
    {
        for (int j = 0; j < resource; j++)
            cout << need_mat[i][j] << " ";
        cout << endl;
    }
    cout << "*********************************" << endl;
    for (int i = 0; i < resource; i++)
    {
        for (int j = 0; j < process; j++)
            sum[i] += allocated[j][i];
    }

    cout << "FREE RESOURCES: " << endl;
    for (int i = 0; i < resource; i++)
        cout << char('A' + i) << " ";
    cout << endl;
    for (int i = 0; i < resource; i++)
    {
        free_mat[i] = total[i] - sum[i];
        available[i] = free_mat[i];
        cout << free_mat[i] << " ";
    }

    int idx = 0;
    bool flag = true;
    int completed[process] = {0};
    int pro_hsh[process] = {0};
    cout << endl;
    cout<<"AVAILABLE RESOURCES: "<<endl;
    for (int k = 0; k < process; k++)
    {
        for (int i = 0; i < process; i++)
        {
            if (completed[i] == 0)
            {
                bool flag4 = true;
                for (int j = 0; j < resource; j++)
                {
                    if (need_mat[i][j] > free_mat[j])
                    {
                        flag4 = false;
                        break;
                    }
                }

                if (flag4)
                {
                    pro_hsh[idx++] = i;
                    for (int y = 0; y < resource; y++){
                        free_mat[y] += allocated[i][y];
                        cout<<free_mat[y]<<" ";
                    }
                    cout<<endl;
                    completed[i] = 1;
                }
            }
        }
    }
        cout<<endl;
    flag = true;
    for (int i = 0; i < process; i++)
    {
        if (completed[i] == 0)
        {
            flag = false;
            cout << "The following system is not safe";
            break;
        }
    }
    if (flag)
    {
        cout << "Following is the SAFE Sequence\n";
        for (int i = 0; i < process - 1; i++)
            cout << " P" << pro_hsh[i] << "->";
        cout << " P" << pro_hsh[process - 1];
    }
    cout << endl;
    cout << "Request for a particular process: (1/0) ";
    int req;
    cin >> req;
    if (req)
    {
        cout << "Enter process number: ";
        int pro;
        cin >> pro;
        int request[resource] = {0};
        cout << "Enter resources: ";
        for (int i = 0; i < resource; i++)
        {
            cin >> request[i];
            available[i] -= request[i];
        }

        for (int i = 0; i < process; i++)
        {
            if (i == pro)
            {
                for (int j = 0; j < resource; j++)
                {
                    allocated[i][j] += request[j];
                    need_mat[i][j] -= request[j];
                }
                break;
            }
        }
        bool flag1 = true;
        for (int i = 0; i < resource; i++)
        {
            if (available[i] < 0)
            {
                flag1 = false;
                break;
            }
        }
        bool flag2 = true;

        for (int i = 0; i < process; i++)
        {
            for (int j = 0; j < resource; j++)
            {
                if (i == pro && need_mat[i][j] < 0)
                {
                    flag2 = false;
                    break;
                }
                if (flag2 == false)
                    break;
            }
        }
        if (flag1 && flag2)
        {
            cout << "Available resources after request: " << endl;
            for (int i = 0; i < resource; i++)
                cout << char('A' + i) << " ";
            cout << endl;
            for (int i = 0; i < resource; i++)
            {
                cout << available[i] << " ";
            }
            cout << endl;
            cout << "NEED MATRIX " << endl;
            for (int i = 0; i < resource; i++)
                cout << char('A' + i) << " ";
            cout << endl;
            for (int i = 0; i < process; i++)
            {
                for (int j = 0; j < resource; j++)
                {
                    cout << need_mat[i][j] << " ";
                }
                cout << endl;
            }
            cout << "ALLOCATED MATRIX " << endl;
            for (int i = 0; i < resource; i++)
                cout << char('A' + i) << " ";
            cout << endl;
            for (int i = 0; i < process; i++)
            {
                for (int j = 0; j < resource; j++)
                {
                    cout << allocated[i][j] << " ";
                }
                cout << endl;
            }
            idx = 0;
            bool flag3 = true;
            int completed1[process] = {0};
            int pro_hsh1[process] = {0};
            cout << endl;
            cout<<"Available Resources: "<<endl;
            for (int k = 0; k < process; k++)
            {
                for (int i = 0; i < process; i++)
                {
                    if (completed1[i] == 0)
                    {
                        bool flag10 = true;
                        for (int j = 0; j < resource; j++)
                        {
                            if (need_mat[i][j] > available[j])
                            {
                                flag10 = false;
                                break;
                            }
                        }

                        if (flag10)
                        {
                            pro_hsh1[idx++] = i;
                            for (int y = 0; y < resource; y++){
                                available[y] += allocated[i][y];
                                cout<<available[y]<<" ";
                            }
                            cout<<endl;
                            completed1[i] = 1;
                        }
                    }
                }
            }
            bool flagL = true;
            for (int i = 0; i < process; i++)
            {
                bool flag11 = true;
                if (completed1[i] == 0)
                {
                    flagL = false;
                    cout << "The following system is not safe";
                    break;
                }
            }
                if (flagL)
                {
                    cout << "Following is the SAFE Sequence\n";
                    for (int i = 0; i < process - 1; i++)
                        cout << " P" << pro_hsh1[i] << "->";
                    cout << " P" << pro_hsh1[process - 1];
                }
            
        }

        else
        {
            cout << "Request cannot be fulfilled.";
        }
    }
}
