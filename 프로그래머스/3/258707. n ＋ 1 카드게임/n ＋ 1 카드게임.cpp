#include <string>
#include <vector>
#define PLAYER 1
#define DRAWCARD 2
#define USE 3
using namespace std;
vector<int> whereCards;
int rnd = 0;

int solution(int coin, vector<int> cards) {
    
    int N = cards.size();
    whereCards.resize(N + 1);
    int idx = N / 3;  // 내가 뽑은 카드의 마지막 위치를 기억하는 변수
    
    // n/3 개를 뽑는다
    for(int i = 0; i < idx; i++) {
        whereCards[cards[i]] = PLAYER;
    }
    
    // 라운드별로 확인
    while(true) {
        rnd++;

        // 카드 더미에 카드가 없으면 종료
        if(idx >= N - 1) break;

        // 카드 2장을 드로우한 카드들로 옮긴다
        for(int i = idx; i < idx + 2; i++) {
            whereCards[cards[i]] = DRAWCARD;
        }
        idx += 2;

        bool succ = false;

        // n+1을 만들 수 있는 카드가 있는지 확인한다
        for(int i = 0; i < idx; i++) {
            // 내 손에 있는 경우
            if(whereCards[cards[i]] == PLAYER) {
                // n-1카드가 내 손에 있는 경우
                // 카드 두 장을 사용하고 턴 종료
                if(whereCards[N + 1 - cards[i]] == PLAYER) {
                    whereCards[cards[i]] = USE;
                    whereCards[N + 1 - cards[i]] = USE;

                    succ = true;
                    break;
                }

                // n-1카드가 드로우한 카드 뭉치에 있는 경우
                if(whereCards[N + 1 - cards[i]] == DRAWCARD) {
                    // 사용할 수 있는 코인이 있는 경우
                    // 코인 사용, 카드 사용 후 다음 턴으로 이동
                    if(coin >= 1) {
                        coin--;
                        whereCards[cards[i]] = USE;
                        whereCards[N + 1 - cards[i]] = USE;

                        succ = true;
                        break;
                    }
                }
            }
            // 해당 카드가 드로우한 카드 뭉치에 있는 경우
            if(whereCards[cards[i]] == DRAWCARD) {
                // n-1 카드가 내 손에 있는 경우
                if(whereCards[N + 1 - cards[i]] == PLAYER) {
                    // 사용할 수 있는 코인이 있는 경우
                    // 코인 사용, 카드 사용 후 다음 턴으로 이동
                    if(coin >= 1) {
                        coin--;
                        whereCards[cards[i]] = USE;
                        whereCards[N + 1 - cards[i]] = USE;

                        succ = true;
                        break;
                    }
                }

                // n-1 카드가 드로우한 카드 뭉치에 있는 경우
                if(whereCards[N + 1 - cards[i]] == DRAWCARD) {
                    // 사용할 수 있는 코인이 있는 경우
                    // 코인 사용, 카드 사용 후 다음 턴으로 이동
                    if(coin >= 2) {
                        coin = coin - 2;
                        whereCards[cards[i]] = USE;
                        whereCards[N + 1 - cards[i]] = USE;

                        succ = true;
                        break;
                    }
                }
            }
        }

        if(succ == false) {
            break;
        }
    }
    

    return rnd;
}