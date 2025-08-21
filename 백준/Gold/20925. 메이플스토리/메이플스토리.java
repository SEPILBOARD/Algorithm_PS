import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        Maple maple = new Maple(n, Integer.parseInt(st.nextToken()));
        
        for(int i =0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            maple.setField(i, Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        for(int i =0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j =0; j<n; j++){
                maple.setMoveTime(i, j, Integer.parseInt(st.nextToken()));
            }
        }
        bw.write(maple.exp()+"\n");
        bw.flush();
        bw.close();
    }
}

class Maple
{
    int time;
    int[][] field;
    int[][] moveTime;
    int[][] dp;

    public Maple(int n, int t)
    {
        this.time = t;
        field = new int[n][2];
        moveTime = new int[n][n];
        dp = new int[t+1][n];
        for(int i =0; i<t+1; i++){
            Arrays.fill(dp[i], -1);    
        }
    }

    public void setField(int i, int con, int exp)
    {
        field[i][0] = con;
        field[i][1] = exp;
    }

    public void setMoveTime(int i, int j, int t)
    {
        moveTime[i][j] = t;
    }

    public int exp()
    {
        for(int i =0; i<field.length; i++){
            if(field[i][0] ==0){
                dp[0][i] =0;
            }
        }
        for(int t =1; t<time+1; t++){
            for(int i =0; i<field.length; i++){
                if(dp[t-1][i] != -1){
                    dp[t][i] = dp[t-1][i] + field[i][1];
                }
                for(int j =0; j<field.length; j++){
                    int prev= t - moveTime[i][j];
                    if(i==j || prev <0){ continue;}

                    if(dp[prev][j]!=-1 && dp[prev][j]>=field[i][0]){
                        dp[t][i] = Math.max(dp[t][i], dp[prev][j]);
                    }
                }
            }
        }
        int result =0;
        for(int i=0;i<field.length;i++ ){
            result = Math.max(result, dp[time][i]);
        }
        return result;
    }
}