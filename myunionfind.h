#ifndef MYUNIONFIND_H
#define MYUNIONFIND_H

namespace graph {

    class myunionfind {
    private:
        int* parent;
        int* rank;
        int size;

    public:
        myunionfind(int n);
        ~myunionfind();

        int find(int x);
        void unite(int x, int y);
        bool connected(int x, int y);
    };

} // namespace graph

#endif // MYUNIONFIND_H
