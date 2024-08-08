#Shoot to Thirty

def get_score(val, mod):
    if (val + 1) % mod == 30 or (val + 2) % mod == 30 or (val + 3) % mod == 30 or (val * 2) % mod == 30 or (val * 3) % mod == 30 or (val ** 2) % mod == 30:
        return True
    return False

def play_game(k, n, s):
    dp = [[None for _ in range(n * 2 + 1)] for _ in range(k)]
    
    def can_win(current_score, turns_left, is_alice_turn):
        if turns_left == 0:
            return False
        if dp[current_score][turns_left] is not None:
            return dp[current_score][turns_left]
        
        if get_score(current_score, k):
            dp[current_score][turns_left] = True
            return True
        
        if is_alice_turn:
            next_turn = False
        else:
            next_turn = True
        
        possible_moves = [
            (current_score + 1) % k,
            (current_score + 2) % k,
            (current_score + 3) % k,
            (current_score * 2) % k,
            (current_score * 3) % k,
            (current_score ** 2) % k
        ]
        
        if any(not can_win(move, turns_left - 1, next_turn) for move in possible_moves):
            dp[current_score][turns_left] = True
            return True
        
        dp[current_score][turns_left] = False
        return False
    
    if can_win(s, n * 2, True):
        return "Alice"
    elif can_win(s, n * 2, False):
        return "Bob"
    else:
        return "Draw"

def main():
    t = int(input())
    ans = []
    for tc in range(t):
        k, n, s = list(map(int, input().split(" ")))
        
        # append answer to test case here
        ans.append(play_game(k, n, s))
        
    print("\n".join(ans))

if __name__ == "__main__":
    main()