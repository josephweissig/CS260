#ifndef _NODEHPP_
#define _NODEHPP_

#include <vector>

template <typename T>
struct Node {
    T data;
    std::vector<Node<T>*> edges;
};

#endif // _NODEHPP_