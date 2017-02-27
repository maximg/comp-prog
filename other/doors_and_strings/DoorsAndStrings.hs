
-- rank, length
perms :: Int -> Int -> Int

perms rank length | length < 0 = 0
				  | rank < 0 = 0
                  | rank > length = 0
				  | rank == length = 1
                  | otherwise = (perms (rank + 1) (length - 1)) + (perms (rank - 1) (length - 1))

-- calc rank of a sequence
rank :: [Char] -> Int
rank [] = 0
rank ['('] = 1
rank [')'] = -1
rank x :: xs = rank [x] + rank xs

solution :: Int -> Int -> [Char] -> Int
solution n m xs =
	let r = rank xs
		len = length xs

	-- for all possible lengths of prefix
	-- for all possible ranks of prefix
	-- calculate the number of permutations of prefix
	-- calculate number of permutations of suffix
	-- accumulate

	-- take mod 10 ^ 9 + 7
