module P2550 where
    verify :: [Int] -> [[Int]] -> [Int]
    verify prize xs = let cs = verify' prize xs in
            map (\x -> count x cs) [7, 6, 5, 4, 3, 2, 1]
        where
            count c = length . filter (\x -> x == c) 

    -- Prize Tickets HitCounts
    verify' :: [Int] -> [[Int]] -> [Int]
    verify' prize = map (\x -> hit_count prize x)
    
    hit_count :: [Int] -> [Int] -> Int
    hit_count prize xs = foldr (\b x -> x + if b then 1 else 0) 0 $ map (\x -> elem x prize) xs 