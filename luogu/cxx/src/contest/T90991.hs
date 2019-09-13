main :: IO ()
main = do
    n <- read <$> getLine :: IO Integer

    print (if n == 1 then 10 else (n - 1) * 14)

    return ()