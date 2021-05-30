#include <iostream>
#include <assert.h>
#include <cstring>

using namespace std;

class CBitset
{
    typedef unsigned long ULONG;
public:
    CBitset(size_t _Size) {
        m_size = _Size;
        m_data_size = (_Size / sizeof(ULONG)) + ((_Size % sizeof(ULONG)) != 0);
        m_data = new ULONG[m_data_size];
        memset(m_data, 0, sizeof(ULONG) * m_data_size);
    }

    ~CBitset() {
        if (m_data)
            delete[] m_data;
    }

    bool test(size_t _Pos) {
        assert(_Pos < m_size);
		return ((m_data[_Pos / sizeof(ULONG)] & (1U << (_Pos % sizeof(ULONG)))) != 0);
    }

    void set(size_t _Pos) {
        assert(_Pos < m_size);
        m_data[_Pos / sizeof(ULONG)] |= (1U << (_Pos % sizeof(ULONG)));
    }

    void set() {
        memset(m_data, 0xFF, sizeof(ULONG) * m_data_size);
    }

    void reset(size_t _Pos) {
        assert(_Pos < m_size);
        m_data[_Pos / sizeof(ULONG)] &= ~(1U << (_Pos % sizeof(ULONG)));
    }

    void reset() {
        memset(m_data, 0, sizeof(ULONG) * m_data_size);
    }

    void flip(size_t _Pos) {
        m_data[_Pos / sizeof(ULONG)] ^= (1U << (_Pos % sizeof(ULONG)));
    }

private:
    size_t m_size;
    size_t m_data_size;
    ULONG* m_data;
};


int main(int argc, char* a[])
{
    CBitset bit(32);
    bit.set(10);
    cout << "set(10)\t\t" << bit.test(10) << endl;
    bit.reset(10);
    cout << "reset(10)\t" << bit.test(10) << endl;
    bit.flip(10);
    cout << "flip(10)\t" << bit.test(10) << endl;

	return 0;
}
