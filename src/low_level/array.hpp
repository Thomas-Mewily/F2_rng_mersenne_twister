#ifndef low_level_array
#define low_level_array
#include "__base__.hpp"

template<typename T>
class array
{
    public:

    explicit array(usize size);
    explicit array();
    array(initializer_list<T> initList);
    //vec(const vec<T>& other);

    //~array(); // do nothings

    void drop();
    bool resize(usize length);
    array<T> clone();

    T& operator[](usize index);
    const T& operator[](usize index) const;
    bool operator==(const array<T>& b) const;
    bool operator!=(const array<T>& b) const;

    usize length() const;
    bool is_empty() const;

    void write(file* f);

    bool idx_valid(usize index) const;

    private:
    T* data    = null;
    usize len  = 0;
};

#include "array_impl.hpp"
#endif
