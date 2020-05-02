//    MIT License
//
//    Copyright (c) 2019 https://github.com/liangdahong
//
//    Permission is hereby granted, free of charge, to any person obtaining a copy
//    of this software and associated documentation files (the "Software"), to deal
//    in the Software without restriction, including without limitation the rights
//    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//    copies of the Software, and to permit persons to whom the Software is
//    furnished to do so, subject to the following conditions:
//
//    The above copyright notice and this permission notice shall be included in all
//    copies or substantial portions of the Software.
//
//    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//    SOFTWARE.

#import <UIKit/UIKit.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;


@end



//
//#!/bin/bash
//
//COLOR_ERR="\033[1;31m"    #出错提示
//COLOR_SUCC="\033[0;32m"  #成功提示
//COLOR_QS="\033[1;37m"  #问题颜色
//COLOR_AW="\033[0;37m"  #答案提示
//COLOR_END="\033[1;34m"     #颜色结束符
//
//# 寻找项目的 ProjectName
//function searchProjectName () {
//  # maxdepth 查找文件夹的深度
//  find . -maxdepth 1 -name "*.xcodeproj"
//}
//
//function oclintForProject () {
//
//    # 预先检测所需的安装包是否存在
//    if which xcodebuild 2>/dev/null; then
//        echo 'xcodebuild exist'
//    else
//        echo '❌❌❌ xcodebuild 都没有安装'
//    fi
//
//    if which oclint 2>/dev/null; then
//        echo 'oclint exist'
//    else
//        echo '❌❌❌  oclint 未安装'
//    fi
//    if which xcpretty 2>/dev/null; then
//        echo 'xcpretty exist'
//    else
//        gem install xcpretty
//    fi
//
//    # 指定编码
//    export LANG="zh_CN.UTF-8"
//    export LC_COLLATE="zh_CN.UTF-8"
//    export LC_CTYPE="zh_CN.UTF-8"
//    export LC_MESSAGES="zh_CN.UTF-8"
//    export LC_MONETARY="zh_CN.UTF-8"
//    export LC_NUMERIC="zh_CN.UTF-8"
//    export LC_TIME="zh_CN.UTF-8"
//    export xcpretty=/usr/local/bin/xcpretty # xcpretty 的安装位置可以在终端用 which xcpretty找到
//
//    searchFunctionName=`searchProjectName`
//    path=${searchFunctionName}
//    # 字符串替换函数。//表示全局替换 /表示匹配到的第一个结果替换。
//    path=${path//.\//}  # ./BridgeLabiPhone.xcodeproj -> BridgeLabiPhone.xcodeproj
//    path=${path//.xcodeproj/} # BridgeLabiPhone.xcodeproj -> BridgeLabiPhone
//
//    myworkspace=$path".xcworkspace" # workspace名字
//    myscheme=$path  # scheme名字
//
//    # 清除
//    xcodebuild -scheme $myscheme -workspace $myworkspace  clean
//
//    # 编译
//    xcodebuild -scheme $myscheme -workspace $myworkspace -configuration Debug | xcpretty -r json-compilation-database -o compile_commands.json
//
//    # 生成
//    oclint-json-compilation-database  \
//    -e AppDelegate \
//    -e Classes \
//    -e Lib \
//    -e Pods \
//    -- -report-type xcode \
//    -disable-rule ShortVariableName \
//    -disable-rule ObjCAssignIvarOutsideAccessors \
//    -disable-rule AssignIvarOutsideAccessors \
//    -max-priority-1=100000 \
//    -max-priority-2=100000 \
//    -max-priority-3=100000
//    # 删除文件 compile_commands.json
//    rm -rf compile_commands.json
//}
//
//oclintForProject
