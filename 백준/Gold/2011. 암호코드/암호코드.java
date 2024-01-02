import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	public static final int MOD=1000000;
	
	public static int solution(String code, int n) {
		int answer=0;
		int [] sample= new int [code.length()];
		int [] dp= new int[code.length()];
		for(int i=0; i<sample.length; i++) {
			sample[i]= Character.getNumericValue(code.charAt(i));
			dp[i]=0;
		}
		if(sample[0]==0) return 0;
		else {
			dp[0]=1;
		}
		for(int i=1; i<n; i++) {
			if(sample[i]==0) {//0일 떄
				if(sample[i-1]==0 || sample[i-1]>2) break;
				else {
					if(i==1) dp[i]=1;
					else dp[i]=dp[i-2];
				}
			}
			else {//0이 아닐 때
				if((sample[i-1]>2)||(sample[i-1]==2&&sample[i]>6)||sample[i-1]==0) dp[i]=dp[i-1];
				else {
					if(i==1) dp[i]=2;
					else dp[i]=dp[i-1]+dp[i-2];
				}
			}
			dp[i]%=MOD;
		}
		
		answer= dp[n-1];
		return answer;
	}
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str= br.readLine();
		int answer = solution(str,str.length());
		System.out.println(answer);
	}

}
