ROOM1_SCORE = 8
ROOM2_SCORE = 10
ROOM3_SCORE = 10
ROOM4_SCORE = 15

n_players = int(input())
players = [0] * n_players

def is_prime(n):
    if n < 2:
        return False

    for dividend in range(2, n):
        if n % dividend == 0:
            return False

    return True

def room1(n_in_room, players_in_room):
    if n_in_room == 0:
        return 

    split = ROOM1_SCORE / n_in_room

    for player in players_in_room:
        players[player] += split

def room2(n_in_room, players_in_room):
    if n_in_room == 0 or n_in_room < 3:
        return

    total = sum(players[x] for x in players_in_room)

    if total == 0:
        # Split evenly
        split = ROOM2_SCORE / n_in_room

        for player in players_in_room:
            players[player] += split
    else:
        # Split according to ratio
        for player in players_in_room:
            ratio = players[player] / total
            players[player] += ROOM2_SCORE * ratio

def room3(n_in_room, players_in_room):
    if n_in_room == 0 or n_in_room > 4:
        return

    split = ROOM3_SCORE / n_in_room

    for player in players_in_room:
        players[player] += split + n_in_room

def room4(n_in_room, players_in_room):
    if n_in_room == 0 or is_prime(n_in_room):
        return

    extra_points = 5
    stored = [-1] * n_players

    while extra_points > (5 - n_in_room) and extra_points > 0:
        biggest = max(players[x] for x in players_in_room)
        biggest_count = 0

        for player in players_in_room:
            if players[player] == biggest:
                stored[player] = players[player] + extra_points
                players[player] = -1
                biggest_count += 1

        extra_points -= biggest_count

    for i in range(n_players):
        if players[i] == -1:
            players[i] = stored[i]

    split = ROOM4_SCORE / n_in_room

    for player in players_in_room:
        players[player] += split

for n_round in range(5):
    for room in range(4):
        n_in_room = int(input())

        if n_in_room == 0:
            players_in_room = []
        else:
            players_in_room = [int(x) - 1 for x in input().split()]

        if room == 0:
            room1(n_in_room, players_in_room)
        elif room == 1:
            room2(n_in_room, players_in_room)
        elif room == 2:
            room3(n_in_room, players_in_room)
        elif room == 3:
            room4(n_in_room, players_in_room)

    print(f"Round {n_round + 1}:")
    for i in range(n_players):
        print(f"Player {i + 1}:", round(players[i], 1))

print("Final:")
for player in players:
    print(round(player, 1))
