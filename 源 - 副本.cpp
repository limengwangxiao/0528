/*
字符串相关的内容 涉及到的比较多的内容 包括hash、partition、 从后向前方式的遍历、两边同时遍历
1、0-1 交换  0110010010001  把所有0 放到1  的前面 --- partition 过程
2、字符的删除和复制  abcabbbacccabb  把所有的a 去掉，并把所有的b复制一份，放在原来b的后面     ---从后面开始遍历
3、交换*   *2*45*45**74  把所有的* 都放到 数字的前面   ---   即可以从后遍历, 也可以partition 过程
4、变位词  判断 b 是否是 a  的变位词
5、字符串的翻转  abcdef  将n个字符 移到原串的后面
6、字符串的包含     判断A是否包含B 中的所有的字符  先对两个串进行排序，再顺序的查询
7、字符串的翻转 输入： “I am a student.”，则输出“student. a am I”  先全部转化为 逆序，再用同样的函数 对每一个单词逆序
字符串的问题 一般可以用到比较巧妙的方法去解决，
	划分
	从后开始遍历
	从两端同时开始遍历

*/

#include <iostream>
#include <string>
using namespace std;
#define SWAP(a,b){int c=a;a=b;b=c;}
void fun_7(char* i,char* j){
	while(i<j){
		SWAP(*i,*j);
		++i,--j;
	}
}
void fun_4(string a,string b){
	int num[26];
	memset(num,0,26);
	int nZero = 0;
	for(int i=0;i<b.size();i++){
		num[b[i]-'a']++;
		if(num[b[i]-'a']==1){
			nZero ++;
		}
	}
	for(int i=0;i<b.size();i++){ //第一个滑动窗口
		num[a[i]-'a'] --;
		if(num[a[i]-'a']==0){ //
			nZero --;
		}
 	}
	
	for(int i=b.size();i<a.size();i++){ //下一个滑动窗口  i 移动一位就是一个滑动窗口
		//去除上一个窗口的第一个字符
		num[a[i-b.size()]-'a']++;
		if(num[a[i-b.size()]-'a']==1){
			nZero ++;
		}
		//增加第i个字符 + 前一个窗口的后两个字符 组成 下一个 滑动窗口
		num[a[i]-'a']--;
		if(num[a[i]-'a']==0){
			nZero --;
		}
		if(nZero==0){
			cout << "变位词" << endl;
		}
	}
	cout << nZero << endl;
}
void fun_3(int *a,int l, int h){
	int j=l;
	for(int i=l;i<h;i++){
		if(a[i]=='*'){
			SWAP(a[i],a[j++]); //j 比 i 慢， 而 j代表的是数字，
								//所以总体的思想就是 把 前面的数字j 换到后面*的位置i上
								//存在两种情况  1、a[j] 是数字，是理想中的交换的方式
											 //2、a[i] 是 * ，则 这种情况只会出现在 i j指向同一个位置的情况
												//因 i j 在指向的都是数字的情况下  则j会保留当前的这个数字 i向前移动 直到
										//i指向的是一个 * ，而此时 i j 之间的必然全是 数字 且不可能出现 j此时指向的是*
							
		}
	}
}
void fun_1(int *a,int l, int r){
	while(l<r){
		while(l<r&&a[l]==0){
			l++;
		}
		while(l<r&&a[r]==1){
			r--;
		}
		SWAP(a[l],a[r]);
	}
}
void fun_2(string& ch){
	int n = 0;
	int num_b = 0;
	for(int i=0;ch[i]!='\0';i++){
		if(ch[i]!='a'){ //删除a  n的速度比i慢 开始不为a的时候 直接复制，碰到a后 n的速度比i慢，所以有几个a 就会错开几个 位置
			ch[n++] = ch[i];
		}
		if(ch[i]=='b'){
			num_b ++;
		}
	}
	//从后向前 复制 b
	int newlen = n + num_b;
	ch.resize(newlen);
	
	for(int i=newlen-1,j=n-1;j>=0;j--){
		ch[i--] = ch[j];
		if(ch[j]=='b'){
			ch[i--]='b';
		}
	}
}
int main(){
	int  a[10] ={0,1,1,0,1,1,0,0,1,0};
	string s = "I am a student.";
	string s2 = "cbb";
	//fun_4(s,s2);
//	cout << s << endl;
	fun_7(&s[0],&s[0]+s.size()-1);
	cout << s << endl;
	int cur=0,t=0;
	for(int i=0;i<s.size();){  
		if(s[i]!=' '){
			i++;
		}else{
			fun_7(&s[0]+cur,&s[0]+i-1);
			cur = i++ + 1;
		}
	}

	for(int i=0;i<10;i++){
		cout << a[i] <<endl;
	}
}