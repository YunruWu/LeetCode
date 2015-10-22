/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
 */

/*
归下类的话，有四种字符串：
1. "/"：为目录分隔符，用来分隔两个目录。
2. "."：当前目录
3. ".."：上层目录
4. 其他字符串：目录名

简化的核心是要找出所有的目录，并且如果遇到".."，需要删除上一个目录。
 */
class Solution {
public:
    string simplifyPath(string path) {
        string result;
        vector<string> allDir;

        string temp;
        path.push_back('/');  // handle cases like "/.."
        for (int i = 0; i < path.length(); i++) {
        	if (path[i] == '/') {
        		if (temp.empty()) continue;
        		else if (temp == ".") {
        			temp.clear();
        		}
        		else if (temp == "..") {
        			if (!allDir.empty()) {
        			    allDir.pop_back();
        			}
        			temp.clear();
        		}
        		else {
        			allDir.push_back(temp);
        			temp.clear();
        		}
        	}
        	else {
        		temp.push_back(path[i]);
        	}
        }

        for (int i = 0; i < allDir.size(); i++) {
        	result += "/" + allDir[i];
        }
        if (result.empty()) result = "/";  // handle the edge case "/../" => "/"
        return result;
    }
};


// using getline() to split the string with '/'
string simplifyPath(string path) {
    string res, tmp;
    vector<string> stk;
    stringstream ss(path);
    while(getline(ss,tmp,'/')) {
        if (tmp == "" or tmp == ".") continue;
        if (tmp == ".." and !stk.empty()) stk.pop_back();
        else if (tmp != "..") stk.push_back(tmp);
    }
    for(auto str : stk) res += "/"+str;
    return res.empty() ? "/" : res;
}