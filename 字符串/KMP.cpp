int my_next[MAXN], n;

void getNext(char str[], int len)
{
	int j = -1;
	my_next[0] = -1;
	for(int i=1;i<len;i++){
		while(j != -1 && str[i] != str[j+1]){
			j = my_next[j];
		}
		if(str[i] == str[j+1]){
			j++;
		}
		my_next[i] = j;
	}
}

// 获取最小循环节长度
int getMinRep(char s[])
{
    int len = strlen(s);
    getNext(s,len);
    int min_repetend = len - my_next[len];
    if(len % min_repetend == 0 && len != min_repetend) {
        return min_repetend;
	} else {
        return len;
	}
}

/*
 单单是统计次数的话，只用把有ans的行取消掉注释就好了！！
*/
bool kmp(char text[], char pattern[])
{
	
	// int lastPos = -1;
	// int ans = 0;
	int n = (int)strlen(text);
	int m = (int)strlen(pattern);
	getNext(pattern, m);
	int j = -1;
	for(int i=0;i<n;i++){
		while(j != -1 && text[i] != pattern[j+1]){
			j = my_next[j];
		}
		if(text[i] == pattern[j+1]){
			// if(lastPos < i) lastPos = i;
			j++;
		}
		if(j == m-1){//出现匹配，则存在
			// ans++;
			// j = my_next[j];
			// return lastPos - m + 2;//首次出现的位置
			return true;//是否存在
		}
	}
	// return ans;//返回一共匹配出现了几次
	return false;
}


int main(void)
{
	char text[] = "abababaabc";
	char pattern[] = "ababaab";
	kmp(text, pattern);
	return 0;
}
