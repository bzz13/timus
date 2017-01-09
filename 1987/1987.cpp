#include <iostream>
#include <ostream>
#include <stdio.h>

using namespace std;

typedef unsigned int uint;

struct Matrix
{
    Matrix(const uint rowCount, const uint columnCount)
       : row(rowCount), column(columnCount)
    {
        matrix = new uint*[row];
        // allocate memories related to the number of columns of each row
        for(uint i = 0; i < row; i++)
        {
            matrix[i] = new uint[column];
        }
    }

    ~Matrix()
    {
        for(int i = 0 ; i < row; ++i)
            delete matrix[i];
        delete[] matrix;
    }

    void set_at(const uint x, const uint y, const uint v)
    {
        matrix[y][x] = v;
    }

    uint get_at(const uint x, const uint y) const
    {
        return matrix[y][x];
    }

    long long atColumn(const uint x) const
    {
        long long answer = -1;
        for(uint y = 0; y < row; ++y)
        {
            uint v = get_at(x, y);
            if (v)
            {
                answer = (long long)v;
            }
        }
        return answer;
    }

    friend ostream& operator<<(ostream& os, const Matrix& m)
    {
        for(uint y = 0; y < m.row; ++y)
        {
            for (uint x = 0; x < m.column; ++x)
            {
                os << m.get_at(x, y) << " ";
            }
            os << endl;
        }
        return os;
    }

private:
    const uint row, column;
    uint** matrix;
};


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    // freopen("output.txt", "wt", stdout);
#endif
    uint n, a, b, col, answer;

    cin >> n;

    Matrix matr(n, 100000000);

    for (uint y = 0; y < n; ++y)
    {
        cin >> a >> b;
        for (uint x = a; x <= b; ++x)
        {
            matr.set_at(x, y, y + 1);
        }
    }

    cin >> n;
    for (uint i = 0; i < n; ++i)
    {
        cin >> col;
        cout << matr.atColumn(col) << endl;
    }

    return 0;
}