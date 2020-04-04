#ifndef DB_H
#define DB_H

#include <functional>
#include <vector>
#include <ostream>
#include "data.h"

template <class K, class V>
class DB
{
    template<class fK, class fV> friend std::ostream & operator << (std::ostream & os, DB<fK,fV> const & db);
public:
    DB();
    void insert(Data<K,V>* d);
    void forEach( std::function<void (Data<K,V>*)> f);
    Data<K,V>* find( std::function<bool (Data<K,V>*)> f);
    DB<K,V> filter( std::function<bool (Data<K,V>*)> f);


private:
    std::vector<Data<K,V>*> data;
};

template<class K, class V>
DB<K,V>::DB()
{
    // Nothing to do here
}

template<class K, class V>
void DB<K,V>::insert(Data<K, V> *d)
{
    data.push_back(d);
}

template<class K, class V>
void DB<K,V>::forEach(std::function<void (Data<K, V> *)> f)
{
    for(auto entry: data){
        f(entry);
    }
}

template<class K, class V>
Data<K, V> *DB<K,V>::find(std::function<bool (Data<K, V> *)> f)
{
    for(auto entry: data){
        if(f(entry)) return entry;
    }

    return nullptr;

}

template<class K, class V>
DB<K,V> DB<K,V>::filter(std::function<bool (Data<K, V> *)> f)
{
    DB<K,V> result;
    for(auto entry: data){
        if(f(entry)) result.insert(entry);
    }

    return result;

}


template<class K, class V>
std::ostream & operator << (std::ostream & os, DB<K,V> const & db){
    for(auto data: db.data){
        os << *data <<"\n" << "------------------------\n";
    }
    return os;
}

#endif // DB_H
