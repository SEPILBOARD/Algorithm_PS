import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int testcase, numOfBuilding, numOfRule;
        ACM acm;

        testcase = Integer.parseInt(br.readLine());
        for(int i=0; i<testcase; i++){
            st = new StringTokenizer(br.readLine());
            numOfBuilding = Integer.parseInt(st.nextToken());
            numOfRule = Integer.parseInt(st.nextToken());
            acm = new ACM(numOfBuilding);

            st = new StringTokenizer(br.readLine());
            for(int j=0; j<numOfBuilding; j++)
            {
                acm.buildTime[j] = Integer.parseInt(st.nextToken());
            }

            
            for(int j=0; j<numOfRule; j++)
            {
                st = new StringTokenizer(br.readLine());
                int first = Integer.parseInt(st.nextToken())-1;
                int second = Integer.parseInt(st.nextToken())-1;
                acm.rule[first].add(second);
                acm.inputDgree[second] += 1;
            }
            acm.winningBuilding = Integer.parseInt(br.readLine())-1;

            bw.write(acm.result() + "\n");
        }
        bw.flush();
        bw.close();
    }
}

class ACM{
    int count;
    public int[] buildTime;
    public ArrayList[] rule;
    public int[] inputDgree;
    public int[] timeNote;
    public int winningBuilding;

    ACM(int a){
        count = a;
        buildTime = new int[a];
        inputDgree = new int[a];
        timeNote = new int[a];
        rule = new ArrayList[a];
        for(int i=0; i<a; i++)
        {
            rule[i] = new ArrayList<Integer>();
        }
    }

    public int result()
    {
        Queue<Integer> q = new LinkedList<>();
        for(int i = 0; i<count; i++)
        {
            if(inputDgree[i] ==0)
            {
                q.add(i);
                timeNote[i] = buildTime[i];
            }
        }

        while (!q.isEmpty())
        {
            int poll = q.poll();

            Iterator<Integer> it = rule[poll].iterator();
            while(it.hasNext())
            {
                int a = it.next();
                timeNote[a] = Math.max(timeNote[a], timeNote[poll]+buildTime[a]);
                inputDgree[a] -=1;
                if(inputDgree[a]<=0)
                {
                    q.add(a);
                }
            }
        }
        return timeNote[winningBuilding];
    }
}