class Solution {
public:
    vector<string> under20numName = {"","One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    vector<string> under100numName = {"","","Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    string under1000func(int n){
        string under1000="";
        if(n/100>0){
            under1000+=under20numName[n/100]+" "+"Hundred";
            if(n%100>0)under1000+=" ";            
        }
        
        if(n%100>=20){
            under1000+=under100numName[n%100/10];
            if(n%10!=0){
                under1000+=" ";
            }
            under1000+=under20numName[n%10];
        }
        else{
            under1000+=under20numName[n%100];
        }
        return under1000;
    }
    string numberToWords(int num) {
        if(num==0)return "Zero";
        string res="";
        
        string B=under1000func(num/1000000000);
        if(B!=""){
            if(res!="")res+=" ";
            res+=B+" Billion";   
        }
        string M=under1000func(num%1000000000/1000000);
        if(M!=""){
            if(res!="")res+=" ";
             res+=M+" Million";   
        }
        
        string T=under1000func(num%1000000/1000);
        if(T!=""){
            if(res!="")res+=" "; 
            res+=T+" Thousand";
        }
        if(res!=""&&num%1000!=0)res+=" "; 
        res+=under1000func(num%1000);
        return res;
    }
};