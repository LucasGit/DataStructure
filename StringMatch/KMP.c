
// ***PMT is the CORE OF KMP*** 
// when j item match failed,it means j-1 item is match success
// so whe should use the Next array to get the new j value 
// ------
// the Next array's item and value is get by use all proper prefix and all proper suffix 
// match ,and to find the longest item that was matched,
// -----
// summary [core]
// suffix strings is exist in src string,
// prefix strings is exist in target(model) string
int GetPMT(char* pTarget,int Next[])
{

#if 1
	// the first item do not have prefix and suffix ,so its 0
	Next[0] = 0;
	
	int i = 1; 
	int j = 0;

	int TLen  = strlen(pTarget);
	
	while(i<TLen)
	{
		// match single words
		if(pTarget[i] == pTarget[j])
		{
			Next[i] = j;
			i++;

			// j index is increase when success
			j++;
		}
		else
		{
			// search formar
			j = (0 == j) ? 0 : Next[j-1];
			
		}

		if(0 == j)
		{
			Next[i] = 0;
			i++;
		}
	}

#else
	Next[0] = -1;

	int i = 0;
	int j = -1;

	int TLen = strlen(pTarget)

	while (i < TLen)
	{
		if (j == -1 || pTarget[i] == pTarget[j])
		{
			++i;
			++j;
			Next[i] = j;
		}	
		else
			j = next[j];
	}


#endif
}


// intrudution of KMP and PMT(Parcial Matched Table)
// [Bing ] http://jakeboxer.com/blog/2009/12/13/the-knuth-morris-pratt-algorithm-in-my-own-words/
// [ZhiHu] https://www.zhihu.com/question/21923021/answer/281346746

// KMP match 
int KMPStringMatch(char *pSrc,char *pTarget)
{

	int i = 0;
	int j = 0;
	int SLen - strlen(pSrc);
	int TLen - strlen(pTarget);

	while(i<=SLen && j<=TLen)
	{
		if((pSrc[i] == pTarget[j]))
		{
			j++
		}
		else
		{
			// Next is PMT particial match table
			j = Next[j-1];
		}

		i++;
	}

	// string matched postion in src string 
	if(j>TLen)
	{
		return i-j;
	}
	else
	{
		//
		return -1;
	}
	
}

