class Solution {
public:
    map<string,string> LtoS;
    map<string,string> StoL;
    string tmp="0";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(tmp[tmp.size()-1]=='z'){
            tmp+="0";
        }
        else{
           char tmpc=tmp[tmp.size()-1];
            tmpc+=1;
            tmp[tmp.size()-1]=tmpc;
        }
        LtoS[longUrl]=tmp;
        StoL[tmp]=longUrl;
        return tmp;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return StoL[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));