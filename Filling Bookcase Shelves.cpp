//Top-Down(Memoization)
class Solution {
public:
    int n;
    int WIDTH;
    int t[1001][1001];
    int solve(vector<vector<int>>& books, int i, int remainW, int maxHt) {
        if(i >= n) 
            return maxHt;
        if(t[i][remainW] != -1) 
            return t[i][remainW];
        int bookW = books[i][0];
        int bookH = books[i][1];
        int take = INT_MAX;
        int not_take = INT_MAX;
        if(bookW <= remainW)
            take = solve(books, i+1, remainW - bookW, max(maxHt, bookH));
        not_take = maxHt + solve(books, i+1, WIDTH - bookW, bookH);

        return t[i][remainW] = min(take, not_take);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(t, -1, sizeof(t));
        n = books.size();
        WIDTH = shelfWidth;
        int remainW = shelfWidth;
        return solve(books, 0, remainW, 0);
    }
};

/*
    You are given an array books where books[i] = [thicknessi, heighti] indicates the thickness and height of the ith book. You are also given an integer shelfWidth.    
    We want to place these books in order onto bookcase shelves that have a total width shelfWidth.  
    We choose some of the books to place on this shelf such that the sum of their thickness is less than or equal to shelfWidth, then build another level of the shelf of the bookcase so that the total height of the bookcase has increased by the maximum height of the books we just put down. We repeat this process until there are no more books to place. 
    Note that at each step of the above process, the order of the books we place is the same order as the given sequence of books.
    For example, if we have an ordered list of 5 books, we might place the first and second book onto the first shelf, the third book on the second shelf, and the fourth and fifth book on the last shelf.
    Return the minimum possible height that the total bookshelf can be after placing shelves in this manner.
    
    Example 1:
    Input: books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelfWidth = 4
    Output: 6
    Explanation:
    The sum of the heights of the 3 shelves is 1 + 3 + 2 = 6.
    Notice that book number 2 does not have to be on the first shelf.
    
    Example 2:
    Input: books = [[1,3],[2,4],[3,2]], shelfWidth = 6
    Output: 4
    
    T.C : O(n*n)
    S.C : O(n*n)
*/
