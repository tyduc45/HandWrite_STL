#ifndef RB_TREE_
#define RB_TREE_

#include<functional>
#include <cassert>

// key_t : key type compare_t: compare function lhs < rhs,check src for more details
template <typename key_t,typename compare_t = std::less<key_t>>
struct rb_tree
{
	//tree node
	struct node_t
	{
		node_t* fa;
		node_t* ch[2];     // 0: left 1: right

		key_t data;
		size_t sz;
		bool red;              // true: red, false: black

		/*
		* check whether current non-null node is the right node
		* if it is return true otherwise return false;
		*/
		auto get_ch() const -> bool 
		{
			return this == fa->ch[1];
		}
	};
	using pointer = node_t*;
	using const_pointer = const node_t*; // pointer points to const
	using pointer_const = node_t* const;  // pointer constant

	using compare = compare_t;
	
	pointer root;

	/*
	* {} is used to init compound types 
	* compoare is struct std::less, cannnot init with ()
	* {} is more commonly used
	*/
	rb_tree() : compare{}, root{ nullptr } {} 


	/**
    * @param p root of subtree (may be same as {@code root})
    * @param dir direction. 0: left rotate; 1: right rotate
    * @return new root of subtree
  */
	auto rotate(pointer p, bool dir) -> pointer
	{
		auto g = p->fa;
		auto s = p->ch[!dir];  // new root of the subtree
		assert(s);
		s->sz = p->sz, p->sz = size(p->ch[dir]) + size(s->ch[dir]) + 1; // need testing for auxiliary understanding . keep going 
		auto c = s->ch[dir];
		if (c) c->fa = p;
		p->ch[!dir] = c, s->ch[dir] = p;
		p->fa = s, s->fa = g;
		if (g)
		{
			g->ch[p == g->ch[1]] = s;
		}
		else
		{
			root = s;
		}
		return s;
	}
};


#endif
