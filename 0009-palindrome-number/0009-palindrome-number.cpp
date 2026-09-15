class Solution {
public:
    bool isPalindrome(int x) {
      double y=x;
      double rev=0;
      double n;
    while(x>0){
       n=x%10;
      rev=rev*10+n;
      x=x/10;
    }
    if(rev==y){
        return true;
    }
    else{
        return false;
    }
     }
};