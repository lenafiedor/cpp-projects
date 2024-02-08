#include <iostream>
using namespace std;

class FRUIT_CLASS {

    private:

    unsigned int weight;
    unsigned int lengthOnBranch;

    public:

    FRUIT_CLASS () {
        this->weight = 0;
        this->lengthOnBranch = 0;
    }

    FRUIT_CLASS ( unsigned int length ) {
        this->weight = 0;
        this->lengthOnBranch = length;
    }

    FRUIT_CLASS ( const FRUIT_CLASS& oldFruit ) {
        this->weight = oldFruit.weight;
        this->lengthOnBranch = oldFruit.lengthOnBranch;
    }
    
    unsigned int getLength () {
        return this->lengthOnBranch;
    }

    unsigned int getWeight () {
        return this->weight;
    }

    void growthFruit () {
        if ( this->weight < 32 ) {
            this->weight++;
        }
    }

    void fadeFruit () {
        if ( this->weight > 0 ) {
            this->weight--;
        }
    }

    void pluckFruit () {
        this->weight = 0;
    }
};

class BRANCH_CLASS {

    private:

    unsigned int length;
    unsigned int heightOnTree;
    FRUIT_CLASS fruits [ 128 ];

    public:

    BRANCH_CLASS () {
        this->length = 0;
        this->heightOnTree = 0;
        for ( unsigned int i = 1; i < 129; i++ ) {
            fruits [ i - 1 ] = FRUIT_CLASS( i * 2 );
        }
    }

    BRANCH_CLASS ( unsigned int height ) {
        this->length = 0;
        this->heightOnTree = height;
        for ( unsigned int i = 1; i < 129; i++ ) {
            fruits [ i - 1 ] = FRUIT_CLASS ( i * 2 );
        }
    }

    BRANCH_CLASS( const BRANCH_CLASS& oldBranch ) {
        this->length = oldBranch.length;
        this->heightOnTree = oldBranch.heightOnTree;
        for ( unsigned int i = 0; i < 128; i++ ) {
            this->fruits [ i ] = FRUIT_CLASS ( oldBranch.fruits [ i ] );
        }
    }

    unsigned int getHeight () {
        return this->heightOnTree;
    }

    unsigned int getLength () {
        return this->length;
    }

    unsigned int getFruitsTotal () {
        return this->length / 2;
    }

    unsigned int getWeightsTotal () {
        unsigned int weightsOnBranch = 0;
        for ( unsigned int i = 0; i < this->length / 2; i++ ) {
            weightsOnBranch += fruits [ i ].getWeight();
        }
        return weightsOnBranch;
    }

    void growthBranch () {
        for ( unsigned int i = 0; i < this->length / 2; i++ ) {
            this->fruits [ i ].growthFruit();
        }
        if ( this->length < 256 ) {
            this->length++;
        }
    }

    void fadeBranch () {
        if ( this->length > 0 ) {
            if ( this->length % 2 == 0 ) {
                fruits [ ( length / 2 ) - 1 ].pluckFruit();
            }
            length--;
        }
        for (unsigned int i = 0; i < length / 2; i++ ) {
            fruits [ i ].fadeFruit();
        }
    }

    void harvestBranch ( unsigned int w ) {
        for ( unsigned int i = 0; i < this->length / 2; i++ ) {
            if ( fruits [ i ].getWeight() >= w ) {
                fruits [ i ].pluckFruit();
            }
        }
    }

    void cutBranch ( unsigned int l ) {
        if ( l < ( this->length ) ) {
            for ( unsigned int i = 0; i < ( this->length ) / 2; i++ ) {
                if ( fruits [ i ].getLength() > l ) {
                    fruits [ i ].pluckFruit();
                }
            }
            this->length = l;
        }
    }

    void growthFruit ( unsigned int lnth ) {
        if ( ( lnth % 2 == 0 ) && ( lnth > 0 ) && ( lnth <= ( this->length ) ) ) {
            fruits [ ( lnth / 2 ) - 1 ].growthFruit();
        }
    }

    void fadeFruit ( unsigned int lnth ) {
        if ( ( lnth % 2 == 0 ) && ( lnth > 0 ) && ( lnth <= ( this->length ) ) ) {
            fruits [ ( lnth / 2 ) - 1 ].fadeFruit();
        }
    }

    void pluckFruit ( unsigned int lnth ) {
        if ( ( lnth % 2 == 0 ) && ( lnth > 0 ) && ( lnth <= ( this->length ) ) ) {
            fruits [ ( lnth / 2 ) - 1 ].pluckFruit();
        }
    }

    bool getFruitObject ( unsigned int lnth, FRUIT_CLASS* newFruit ) {
        bool existence = false;
        if ( ( lnth % 2 == 0 ) && ( lnth > 0 ) && ( lnth <= ( this->length ) ) ) {
            *newFruit = fruits [ ( lnth / 2 ) - 1 ];
            existence = true;
        }
        return existence;
    }
};

class TREE_CLASS {

    private:

    unsigned int height;
    unsigned int treeID;
    BRANCH_CLASS branches [ 128 ];

    public:

    TREE_CLASS () {
        this->height = 0;
        this->treeID = 0;
        for ( unsigned int i = 1; i < 129; i++ ) {
            branches [ i - 1 ] = BRANCH_CLASS( i * 3 );
        }
    }

    TREE_CLASS ( unsigned int id ) {
        this->height = 0;
        this->treeID = id;
        for ( unsigned int i = 1; i < 129; i++ ) {
            branches [ i - 1 ] = BRANCH_CLASS ( i * 3 );
        }
    }

    TREE_CLASS ( const TREE_CLASS& oldTree ) {
        this->height = oldTree.height;
        this->treeID = oldTree.treeID;
        for ( unsigned int i = 0; i < 128; i++ ) {
            this->branches [ i ] = BRANCH_CLASS ( oldTree.branches [ i ] );
        }
    }

    unsigned int getNumber () {
        return this->treeID;
    }

    unsigned int getHeight () {
        return this->height;
    }

    unsigned int getBranchesTotal () {
        return this->height / 3;
    }

    unsigned int getFruitsTotal () {
        unsigned int fruitsTotal = 0;
        for ( unsigned int i = 0; i < this->height / 3; i++ ) {
            fruitsTotal += branches [ i ].getFruitsTotal();
        }
        return fruitsTotal;
    }

    unsigned int getWeightsTotal () {
        unsigned int weightsTotal = 0;
        for ( int i = 0; i < this->height / 3; i++ ) {
            weightsTotal += branches [ i ].getWeightsTotal();
        }
        return weightsTotal;
    }

    void growthTree () {
        for ( int i = 0; i < this->height / 3; i++ ) {
            branches [ i ].growthBranch();
        }
        if ( this->height < 384 ) {
            this->height++;
        }
    }

    void fadeTree () {
        if ( this->height > 0 ) {
            for ( unsigned int i = 0; i < height / 3; i++ ) {
                if ( branches [ i ].getHeight() == this->height ) {
                    branches [ i ].cutBranch ( 0 );
                }
            }
            height--;
        }
        for ( unsigned int i = 0; i < 128; i++ ) {
            branches [ i ].fadeBranch();
        }
    }

    void harvestTree ( unsigned int w ) {
        for ( unsigned int i = 0; i < height / 3; i++ ) {
            branches [ i ].harvestBranch ( w );
        }
    }

    void cutTree ( unsigned int h ) {
        for ( int i = 0; i < height / 3; i++ ) {
            if ( branches [ i ].getHeight () > h ) {
                branches [ i ].cutBranch ( 0 );
            }
        }
        if ( h < height ) {
            this->height = h;
        }
    }

    void growthBranch ( unsigned int h ) {
        if ( ( h % 3 == 0 ) && ( h > 0 ) && ( h <= ( this->height ) ) ) {
            branches [ ( h / 3 ) - 1 ].growthBranch();
        }
    }

    void fadeBranch ( unsigned int h ) {
        if ( ( h % 3 == 0 ) && ( h > 0 ) && ( h <= ( this->height ) ) ) {
            branches [ ( h / 3 ) - 1 ].fadeBranch();
        }
    }

    void harvestBranch ( unsigned int h, unsigned int w ) {
        if ( ( h % 3 == 0 ) && ( h > 0 ) && ( h <= ( this->height ) ) ) {
            branches [ ( h / 3 ) - 1 ].harvestBranch ( w );
        }
    }

    void cutBranch ( unsigned int h, unsigned int l ) {
        if ( ( h % 3 == 0 ) && ( h > 0 ) && ( h <= ( this->height ) ) ) {
            branches [ ( h / 3 ) - 1 ].cutBranch ( l );
        }
    }

    void growthFruit ( unsigned int h, unsigned int l ) {
        if ( ( h % 3 == 0 ) && ( h > 0 ) && ( h <= ( this->height ) ) ) {
            branches [ ( h / 3 ) - 1 ].growthFruit ( l );
        }
    }

    void fadeFruit ( unsigned int h, unsigned int l ) {
        if ( ( h % 3 == 0 ) && ( h > 0 ) && ( h <= ( this->height ) ) ) {
            branches [ ( h / 3 ) - 1 ].fadeFruit ( l );
        }
    }

    void pluckFruit ( unsigned int h, unsigned int l ) {
        if ( ( h % 3 == 0 ) && ( h > 0 ) && ( h <= ( this->height ) ) ) {
            branches [ ( h / 3 ) - 1 ].pluckFruit ( l );
        }
    }

    bool getBranchObject ( unsigned int h, BRANCH_CLASS* newBranch ) {
        bool existence = false;
        if ( ( h % 3 == 0 ) && ( h > 0 ) && ( h <= ( this->height ) ) ) {
            *newBranch = branches [ ( h / 3 ) - 1 ];
            existence = true;
        }
        return existence;
    }

    bool getFruitObject ( unsigned int h, unsigned int l, FRUIT_CLASS* newFruit ) {
        bool existence = false;
        if ( ( h % 3 == 0 ) && ( h > 0 ) && ( h <= ( this->height ) ) ) {
            existence = branches [ ( h / 3 ) - 1 ].getFruitObject ( l, newFruit );
        }
        return existence;
    }
};

class GARDEN_CLASS {

    private:

    TREE_CLASS* trees [ 64 ];

    public:

    GARDEN_CLASS () {
        for ( unsigned int i = 0; i < 64; i++ ) {
            trees [ i ] = NULL;
        }
    }

    ~GARDEN_CLASS () {
        for ( unsigned int i = 0; i < 64; i++ ) {
            if ( trees [ i ] != NULL ) {
                delete trees [ i ];
            }
        }
    }

    unsigned int getTreesTotal () {
        int treesTotal = 0;
        for ( unsigned int i = 0; i < 64; i++ ) {
            if ( trees [ i ] != NULL ) {
                treesTotal++;
            }
        }
        return treesTotal;
    }

    unsigned int getBranchesTotal () {
        unsigned int branchesTotal = 0;
        for ( unsigned int i = 0; i < 64; i++ ) {
            if ( trees [ i ] != NULL ) {
                branchesTotal += trees [ i ]->getBranchesTotal();
            }
        }
        return branchesTotal;
    }

    unsigned int getFruitsTotal () {
        unsigned int fruitsTotal = 0;
        for ( unsigned int i = 0; i < 64; i++ ) {
            if ( trees [ i ] != NULL ) {
                fruitsTotal += trees [ i ]->getFruitsTotal();
            }
        }
        return fruitsTotal;
    }

    unsigned int getWeightsTotal () {
        unsigned int weightsTotal = 0;
        for ( unsigned int i = 0; i < 64; i++ ) {
            if ( trees [ i ] != NULL ) {
                weightsTotal += trees [ i ]->getWeightsTotal();
            }
        }
        return weightsTotal;
    }

    void plantTree () {
        for ( unsigned int i = 0; i < 64; i++ ) {
            if ( trees [ i ] == NULL ) {
                trees [ i ] = new TREE_CLASS ( i );
                break;
            }
        }
    }

    void extractTree ( unsigned int id ) {
        if ( ( id < 64 ) && ( trees [ id ] != NULL ) ) {
            delete trees [ id ];
            trees [ id ] = NULL;
        }
    }

    void growthGarden () {
        for ( unsigned int i = 0; i < 64; i++ ) {
            if ( trees [ i ] != NULL ) {
                trees [ i ]->growthTree();
            }
        }
    }

    void fadeGarden () {
        for ( unsigned int i = 0; i < 64; i++ ) {
            if ( trees [ i ] != NULL ) {
                trees [ i ]->fadeTree();
            }
        }
    }

    void harvestGarden ( unsigned int w ) {
        for ( int i = 0; i < 64; i++ ) {
            if ( trees [ i ] != NULL ) {
                trees [ i ]->harvestTree ( w );
            }
        }
    }

    void growthTree ( unsigned int id ) {
        if ( ( id < 64 ) && ( trees [ id ] != NULL ) ) {
            trees [ id ]->growthTree();
        }
    }

    void fadeTree ( unsigned int id ) {
        if ( ( id < 64 ) && ( trees [ id ] != NULL ) ) {
            trees [ id ]->fadeTree();
        }
    }

    void harvestTree ( unsigned int id, unsigned short int w ) {
        if ( ( id < 64 ) && ( trees [ id ] != NULL ) ) {
            trees [ id ]->harvestTree ( w );
        }
    }

    void cutTree ( unsigned int id, unsigned int h ) {
        if ( ( id < 64 ) && ( trees [ id ] != NULL ) ) {
            trees [ id ]->cutTree ( h );
        }
    }

    void growthBranch ( unsigned int id, unsigned int h ) {
        if ( ( id < 64 ) && ( trees [ id ] != NULL ) ) {
            trees [ id ]->growthBranch ( h );
        }
    }

    void fadeBranch ( unsigned int id, unsigned int h ) {
        if ( ( id < 64 ) && ( trees [ id ] != NULL ) ) {
            trees [ id ]->fadeBranch ( h );
        }
    }

    void harvestBranch ( unsigned int id, unsigned int h, unsigned int w ) {
        if ( ( id < 64 ) && ( trees [ id ] != NULL ) ) {
            trees [ id ]->harvestBranch ( h, w );
        }
    }

    void cutBranch ( unsigned int id, unsigned int h, unsigned int l ) {
        if ( ( id < 64 ) && ( trees [ id ] != NULL ) ) {
            trees [ id ]->cutBranch ( h, l );
        }
    }

    void growthFruit ( unsigned int id, unsigned int h, unsigned int l ) {
        if ( ( id < 64 ) && ( trees [ id ] != NULL ) ) {
            trees [ id ]->growthFruit ( h, l );
        }
    }

    void fadeFruit ( unsigned int id, unsigned int h, unsigned int l ) {
        if ( ( id < 64 ) && ( trees [ id ] != NULL ) ) {
            trees [ id ]->fadeFruit ( h, l );
        }
    }

    void pluckFruit ( unsigned int id, unsigned int h, unsigned int l ) {
        if ( ( id < 64 ) && ( trees [ id ] != NULL ) ) {
            trees [ id ]->pluckFruit ( h, l );
        }
    }

    bool getTreeObject ( unsigned int id, TREE_CLASS* newTree ) {
        bool existence = false;
        if ( ( id < 64 ) && ( trees [ id ] != NULL ) ) {
            *newTree = *( trees [ id ] );
            existence = true;
        }
        return existence;
    }

    bool getBranchObject ( unsigned int id, unsigned int h, BRANCH_CLASS* newBranch ) {
        bool existence = false;
        if ( ( id < 64 ) && ( trees [ id ] != NULL ) ) {
            existence = trees [ id ]->getBranchObject ( h, newBranch );
        }
        return existence;
    }

    bool getFruitObject ( unsigned int id, unsigned int h, unsigned int l, FRUIT_CLASS* newFruit ) {
        bool existence = false;
        if ( ( id < 64 ) && ( trees [ id ] != NULL ) ) {
            existence = trees [ id ]->getFruitObject ( h, l, newFruit );
        }
        return existence;
    }
};