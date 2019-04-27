#include <iostream>

using namespace std;
void fractionalKnapsack(int n, int W, int value[], int weight[])
{
	int *itemPicked = new int[n];
	int k = 0, v = 0, i;

	for (i = 0; i < n; i++)
	{
		itemPicked[i] = value[i] / weight[i];
		//cout<<itemPicked[i]<<" ";
	}
	//cout<<"\n";
	
	while( k < W )
	{	
		int m = 0, m_idx = 0;
		for (i = 0; i < n; i++)
		{
			if( m < itemPicked[i] && itemPicked[i] > 0)
			{
				m = itemPicked[i];
				m_idx = i;
			}
		}
		//cout<<"m_idx = "<<m_idx<<endl;
		//cout<<"k = "<<k<<endl;

		if( k + weight[m_idx] < W ) // not enough this time
		{
			k = k + weight[m_idx];
			itemPicked[m_idx] = 0;
			v = v + value[m_idx];
		}
		else if ( (k + weight[m_idx] > W) && (k < W) ) // after this time, it fulls.
		{
			weight[m_idx] = weight[m_idx]  - (W - k);
			v = v + (W - k) * itemPicked[m_idx]; 
			//cout<<(W - k)<<endl;
			k = W;
			itemPicked[m_idx] = 0;
		}
		
		//cout<<"The bag's weight = "<<k<<endl;
		//printf("weight[%d] = %d \n", m_idx, weight[m_idx]);
	}

	cout<<"value = "<<v<<endl;

}
int main()
{
	int n = 3, W = 15;
	int value[] = {10, 6, 21};
	int weight[] = {5, 6, 7};

	fractionalKnapsack(n, W, value, weight);
	return 0;
}