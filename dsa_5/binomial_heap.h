#include <utility>
#include <list>

struct EmptyHeap: public std::exception {};

template<class T>
class BinomialHeap {
    private:
        struct BinomialTree {
            T element;
            std::list<BinomialTree*> children;
            BinomialTree(T _ele): element(_ele) {
                children.clear();
            }
        };
        typedef BinomialTree BT;
        typedef BinomialHeap<T> BH;
        typedef std::pair<BT*, BT*> CarrySum;
        typedef std::pair<T, BH> MaxRemainder;
        CarrySum merge_tree(BT *a, BT *b, BT *c) {
			CarrySum tmp(nullptr, nullptr);
			if(a != nullptr && b != nullptr)
			{
				tmp.first = (a->element > b->element) ? a : b;
				tmp.first->children.push_back( (a->element > b->element) ? b : a );
				tmp.second = c;
			}
			else if(a != nullptr && c != nullptr)
			{
				tmp.first = (a->element > c->element) ? a : c;
				tmp.first->children.push_back( (a->element > c->element) ? c : a );
			}
			else if(b != nullptr && c != nullptr)
			{
				tmp.first = (b->element > c->element) ? b : c;
				tmp.first->children.push_back( (b->element > c->element) ? c : b );
			}
			else	tmp.second = (a == nullptr) ? ((b == nullptr) ? c : b) : a;
			return tmp;
        };
        MaxRemainder pop_max(BT *a) {
			MaxRemainder tmp;
			tmp.first = a->element;
			int i = 0;
			while(!a->children.empty())
			{
				tmp.second.trees[i++] = a->children.front();
				a->children.pop_front();
			}
			tmp.second.size = -1;
			delete a;
			return tmp;
        }
        BT* trees[32];
    public:
        int size;
        BinomialHeap(): size(0) {
            for(int i=0; i<32; ++i) trees[i] = nullptr;
        }
        BinomialHeap(T element): size(1) {
            for(int i=0; i<32; ++i) trees[i] = nullptr;
            trees[0] = new BT(element);
        }
        void merge(BH &b) {
			CarrySum tmp = merge_tree(trees[0], b.trees[0], nullptr);
			trees[0] = tmp.second;
			for(int i = 1 ; i < 32 ; i++)
			{
				tmp = merge_tree(trees[i], b.trees[i], tmp.first);
				trees[i] = tmp.second;
			}
			size += b.size;
			b.size = 0;
			for(int i = 0 ; i < 32 ; i++)	b.trees[i] = nullptr;
        }
        void insert(const T &element) {
            BH tmp = BH(element);
            merge(tmp);
        }
        T pop() {
            if(size==0) throw EmptyHeap();
            else {
                int max_tree = -1;
                for(int i=0; i<32; ++i)
                    if(trees[i] != nullptr && (max_tree == -1 || trees[i]->element > trees[max_tree]->element))
                        max_tree = i;
                MaxRemainder m_r = pop_max(trees[max_tree]);
                T &max_element = m_r.first;
                BH &remainder = m_r.second;
                trees[max_tree] = nullptr;
                merge(remainder);
                return max_element;
            }
        }
		T peek()
		{
			int max_tree = -1;
			for(int i = 0 ; i < 32 ; i++)	if(trees[i] != nullptr && (max_tree == -1 || trees[i]->element > trees[max_tree]->element))	max_tree = i;
			return trees[max_tree]->element;
		}
};
