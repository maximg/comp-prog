-- http://acm.timus.ru/problem.aspx?space=1&num=1222
sol :: Int -> Integer
sol n
  | n < 1 = 0
  | n < 5 = n
  | (n `mod` 3) == 0 = 3 ^ (n `div` 3)
  | otherwise = (2:Integer) * sol (n-2)

main = let iq = sol 3000
  in putStrLn $ "Max IQ: " ++ show iq
