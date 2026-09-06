class Solution {
    Boolean[][] dp;
    public boolean canCross(int[] stones) {
        if(stones[1] != 1) return false;
        int n =  stones.length;
        dp = new Boolean[n][n];
        return solve(stones,1,1);
    }
    public boolean solve(int[] stones, int idx, int lastJump){
        if(idx == stones.length - 1) return true;
        if(dp[idx][lastJump] != null) return dp[idx][lastJump];
        for (int nextJump = lastJump - 1; nextJump <= lastJump + 1; nextJump++){
            if (nextJump <= 0) continue;
            int target = stones[idx] + nextJump;
            int nextIndex = findStoneIdx(stones, idx+1, target);
            if(nextIndex != -1) {
                if(solve(stones,nextIndex, nextJump)) return dp[idx][lastJump]= true;
            }
        }
        return dp[idx][lastJump] = false;
    }
    public int findStoneIdx(int[] stone, int start, int target){
        for (int i = start; i < stone.length; i++){
            if(stone[i]== target) return i;
            if(stone[i]> target) break;
        }
        return -1;
    }
}