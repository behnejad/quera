#include <iostream>
#include <vector>
#include <limits>

using namespace std;

#define ll unsigned long long

std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}

int main()
{
    ll n, k;
    __int128 count = 0;
    cin >> n >> k;
    vector<ll> array(k);

    for (ll i = 0; i < k; ++i)
    {
        cin >> array[i];
    }

    if (k == 1)
    {
        cout << array[0] << endl;
    }
    else
    {
        while (array.size() != 1)
        {
            ll i;
            ll min = numeric_limits<ll>::max();
            for (ll j = 0; j < array.size() - 1; ++j)
            {
                if (array[j] + array[j + 1] < min)
                {
                    min = array[j] + array[j + 1];
                    i = j;
                }
            }

            count += min;
            array[i] = min;
            array.erase(array.begin() + i + 1);
        }

        cout << count << endl;
    }
    return 0;
}
