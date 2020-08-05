#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

class column
{
public:
    column(string name, bool str) : name(name), is_string(str) {}
    string name;
    bool is_string;
};

class row
{
public:
    row(long long val) : i(val) {};
    row(string val) : str(val) {};
    long long i;
    string str;
};

class table
{
public:
    vector<column> colums;
    vector<vector<row>> rows;
};

map<string, bool> users;
map<string, table> tables;

int main()
{
    istringstream cline;
    string line, command, temp, table_name,
            column_name, user, what, role, type;

    getline(cin, line);
    cline.clear();
    cline.str(line);

    cline >> command;
    while (command != "done")
    {
        if (command == "create")
        {
            cline >> what;

            if (what == "user")
            {
                cline >> user >> role;
                users[user] = (role == "editor");
            }
            else if (what == "table")
            {
                cline >> table_name >> user;
                if (users[user])
                {
                    tables[table_name] = table();
                }
                else
                {
                    cout << "access denied" << endl;
                }
            }
        }
        else if (command == "delete")
        {
            cline >> temp >> table_name >> user;
            if (users[user])
            {
                tables.erase(table_name);
            }
            else
            {
                cout << "access denied" << endl;
            }
        }
        else if (command == "add")
        {
            cline >> what >> table_name;
            if (what == "column")
            {
                cline >> column_name >> type >> user;
                if (users[user])
                {
                    table & t = tables[table_name];
                    if (type == "int")
                    {
                        t.colums.emplace_back(column_name, false);
                        for (vector<row> & row_item : t.rows)
                        {
                            row_item.emplace_back(0);
                        }
                    }
                    else
                    {
                        t.colums.emplace_back(column_name, true);
                        for (vector<row> & row_item : t.rows)
                        {
                            row_item.emplace_back("null");
                        }
                    }
                }
                else
                {
                    cout << "access denied" << endl;
                }
            }
            else if (what == "row")
            {
                cline >> user;
                if (users[user])
                {
                    table & t = tables[table_name];
                    vector<row> new_row;
                    for (column & c : t.colums)
                    {
                        if (c.is_string)
                        {
                            new_row.emplace_back("null");
                        }
                        else
                        {
                            new_row.emplace_back(0);
                        }
                    }
                    t.rows.push_back(move(new_row));
                }
                else
                {
                    cout << "access denied" << endl;
                }
            }
        }
        else if (command == "remove")
        {
            cline >> what >> table_name;
            if (what == "column")
            {
                cline >> column_name >> user;
                if (users[user])
                {
                    int index = 0;
                    for (column & t : tables[table_name].colums)
                    {
                        if (t.name == column_name)
                        {
                            break;
                        }
                        else
                        {
                            ++index;
                        }
                    }

                    tables[table_name].colums.erase(tables[table_name].colums.begin() + index);
                    for (vector<row> & r : tables[table_name].rows)
                    {
                        r.erase(r.begin() + index);
                    }
                }
                else
                {
                    cout << "access denied" << endl;
                }
            }
            else if (what == "row")
            {
                int row_id;
                cline >> row_id >> user;

                if (users[user])
                {
                    tables[table_name].rows.erase(tables[table_name].rows.begin() + (row_id - 1));
                }
                else
                {
                    cout << "access denied" << endl;
                }
            }
        }
        else if (command == "change")
        {
            int row_id;
            cline >> table_name >> row_id >> column_name >> temp >> user;
            if (users[user])
            {
                table & t = tables[table_name];
                column * cl;
                int index = 0;
                for (column & c : t.colums)
                {
                    if (c.name == column_name)
                    {
                        cl = &c;
                        break;
                    }
                    else
                    {
                        ++index;
                    }
                }

                row & row_ = t.rows[row_id - 1][index];
                if (cl->is_string)
                {
                    row_.str = temp;
                }
                else
                {
                    row_.i = stoll(temp);
                }
            }
            else
            {
                cout << "access denied" << endl;
            }
        }
        else if (command == "print")
        {
            cline >> table_name;
            table & t = tables[table_name];
            vector<int> cols;

            vector<string> items;
            while (!cline.eof())
            {
                string s;
                cline >> s;
                items.push_back(move(s));
            }

            items.erase(items.end());
            if (items.size() == 1 && items[0] == "*")
            {
                int index = 0;
                for (column & c : t.colums)
                {
                    cols.push_back(index);
                    ++index;
                }
            }
            else
            {
                for (string c_name : items)
                {
                    int index = 0;
                    for (column & c : t.colums)
                    {
                        if (c.name == c_name)
                        {
                            cols.push_back(index);
                            break;
                        }
                        else
                        {
                            ++index;
                        }
                    }
                }
            }

            vector<column> & c = t.colums;
            for (vector<row> & r : t.rows)
            {
                for (int k = 0; k <cols.size(); ++k)
                {
                    int c_ = cols[k];

                    if (c[c_].is_string)
                    {
                        cout << r[c_].str << " ";
                    }
                    else
                    {
                        cout << r[c_].i << " ";
                    }
                }
                cout << endl;
            }
        }
        else if (command == "search")
        {
            cline >> table_name >> column_name >> temp >> user;

            table & t = tables[table_name];
            int ind = 0;
            bool is_str = false;
            vector<column> & cl = t.colums;
            for (column & c : t.colums)
            {
                if (c.name == column_name)
                {
                    is_str = c.is_string;
                    break;
                }
                else
                {
                    ++ind;
                }
            }

            for (vector<row> & r : t.rows)
            {
                if (is_str)
                {
                    if (r[ind].str != temp)
                    {
                        continue;
                    }
                }
                else
                {
                    if (r[ind].i != stoll(temp))
                    {
                        continue;
                    }
                }

                for (int k = 0; k < r.size(); ++k)
                {
                    if (cl[k].is_string)
                    {
                        cout << r[k].str << " ";
                    }
                    else
                    {
                        cout << r[k].i << " ";
                    }
                }
                cout << endl;
            }
        }

        getline(cin, line);
        cline.clear();
        cline.str(line);

        cline >> command;
    }

    return 0;
}
