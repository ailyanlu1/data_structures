//treeADT.h
/*** 
	Methods / Class May or may not work, but it is a good outline
	of what should be inside of the Tree Class
 ***/
template <typename Comparable>
class BinarySearchTree
{
	public:
		BinarySearchTree( );
		BinarySearchTree( const BinarySearchTree & rhs );
		BinarySearchTree( BinarySearchTree && rhs );
		~BinarySearchTree( );
		const Comparable & findMin( ) const;
		const Comparable & findMax( ) const;
		bool contains( const Comparable & x ) const;
		bool isEmpty( ) const;
		void printTree( ostream & out = cout ) const;
		void makeEmpty( );
		void insert( const Comparable & x );
		void insert( Comparable && x );
		void remove( const Comparable & x );
		BinarySearchTree & operator=( const BinarySearchTree & rhs );
		BinarySearchTree & operator=( BinarySearchTree && rhs );
	private:
		struct BinaryNode{
			Comparable element;
			BinaryNode *left;
			BinaryNode *right;
			BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt ) : element{ theElement }, left{ lt }, right{ rt } { }
			BinaryNode( Comparable && theElement, BinaryNode *lt, BinaryNode *rt ) : element{ std::move( theElement ) }, left{ lt }, right{ rt } { }
		};
		BinaryNode *root;
		void insert( const Comparable & x, BinaryNode * & t );
		void insert( Comparable && x, BinaryNode * & t );
		void remove( const Comparable & x, BinaryNode * & t );
		BinaryNode * findMin( BinaryNode *t ) const;
		BinaryNode * findMax( BinaryNode *t ) const;
		bool contains( const Comparable & x, BinaryNode *t ) const;
		void makeEmpty( BinaryNode * & t );
		void printTree( BinaryNode *t, ostream & out ) const;
		BinaryNode * clone( BinaryNode *t ) const;
};
/**
* Returns true if x is found in the tree.
*/
bool BinarySearchTree::contains( const Comparable & x ) const
{
	return contains( x, root );
}
/**
* Insert x into the tree; duplicates are ignored.
*/
void BinarySearchTree::insert( const Comparable & x )
{
	insert( x, root );
}
/**
* Remove x from the tree. Nothing is done if x is not found.
*/
void BinarySearchTree::remove( const Comparable & x )
{
	remove( x, root );
}
/**
* Internal method to test if an item is in a subtree.
* x is item to search for.
* t is the node that roots the subtree.
*/
bool BinarySearchTree::contains( const Comparable & x, BinaryNode *t ) const
{
	if( t == nullptr )
		return false;
	else if( x < t->element )
		return contains( x, t->left );
	else if( t->element < x )
		return contains( x, t->right );
	else
		return true; // Match
}