string = "Rob is a software engineer with three years of experience.  \
  Joe is a software engineer that's been here for eleven years."

module Mod
  @count
  def incrementCount
    @count = @count + 1
  end
  def get
    @count
  end
  def set(x)
    @count = x
  end
end

strSplit = string.gsub(/\?|\.|\,/,'').split(' ').each{
  |str|
  str.extend(Mod)
  str.set(0)
}
strMatch = strSplit

strSplit.each {
  |subStr|
  strMatch.delete_if {
    |matchStr|
    if matchStr == subStr
      subStr.incrementCount > 1
    end
    }
}

strSplit.delete_if {

}

strMatch.each{
  |matchStr|
  $stdout.print(matchStr, "  ",matchStr.get,"\n")
}
