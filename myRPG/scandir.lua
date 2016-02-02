scandir = function()
	i, t = 0, {}
	for dir in io.popen([[dir SavedGames\*.save /b]]):lines() do 
		i = i + 1
		t[i] = dir
	end
	return t
end

result = scandir()