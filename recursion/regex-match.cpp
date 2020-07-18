#include<iostream>
#include<string>
using namespace std;

bool regexMatch(string str,  string regex , int si , int ri)
{
    if(si==str.length() && ri==regex.length())
        return true;
    
    if((si!=str.length() && ri==regex.length()))
        return false;


    if(regex[ri]=='.' && ri<regex.length()-1 && regex[ri+1]!='*')           // a.bc , .abc etc 
        return regexMatch(str,regex,si+1,ri+1);

    else if(regex[ri]=='.' && ri<regex.length()-1 && regex[ri+1]=='*')      // .* 
        return regexMatch(str,regex,si+1,ri+2) || regexMatch(str,regex,si+1,ri);
    
    else if(regex[ri]=='.' && ri==regex.length()-1)                         // last character is .
        return regexMatch(str,regex,si+1,ri+1);

    else if(ri<regex.length()-1 && regex[ri+1]=='*')                        //a*
    {
        if(str[si]==regex[ri])                              // 1 or more occurance of the character
            return regexMatch(str,regex,si+1,ri+2) || regexMatch(str,regex,si+1,ri);
    
        else                                                // 0 occurance of the character
            return regexMatch(str,regex,si,ri+2);
    }

    else                                                                    // Character match
    {
        if(str[si]!=regex[ri])
            return false;
        else
            return regexMatch(str,regex,si+1,ri+1);
    }
}

int main()
{
    string regex = ".*c";
    string str = "ab";
    
    cout<<"Regex match or not :- "<<regexMatch(str,regex,0,0)<<endl;
}