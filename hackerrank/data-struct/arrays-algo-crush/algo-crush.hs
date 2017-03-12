
data Command where
    -- [begin, end)
    Range :: Int -> Int -> Integer -> Command
    deriving (Show)

range :: Int -> Int -> Integer -> Command
range a b k = Range min(a,b) max(a,b)+1 k

