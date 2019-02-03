-- http://acm.timus.ru/problem.aspx?space=1&num=1222
sol :: Integer -> Integer
sol n
  | n < 1 = 0
  | n < 5 = n
  | (n `mod` 3) == 0 = 3 ^ (n `div` 3)
  | otherwise = 2 * sol (n-2)

main :: IO ()
main = do
  iq <- getLine
  putStrLn $ show $ sol $ toInteger $ read iq
