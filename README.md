<p align="center">
    <img  width="22%" src="https://user-images.githubusercontent.com/12118567/89103687-3cbc6400-d446-11ea-9b66-cc349f7b8da4.gif"/>
    <img  width="22%" src="https://user-images.githubusercontent.com/12118567/89103691-40e88180-d446-11ea-8e2e-4d19b1181f4c.gif"/>
<p/>



<p align="center">
<a href="#"><img src="https://img.shields.io/cocoapods/v/UITableViewDynamicLayoutCacheHeight.svg"></a>
<a href="#"><img src="https://img.shields.io/badge/platform-iOS-red.svg"></a>
<a href="#"><img src="https://img.shields.io/badge/language-Objective--C-orange.svg"></a>
<a href="#"><img src="https://img.shields.io/badge/licenses-MIT-red.svg"></a>
</p>

## 介绍

-  [UITableViewDynamicLayoutCacheHeight](https://github.com/liangdahong/UITableViewDynamicLayoutCacheHeight) 是一个便捷的，高性能的自动计算使用 `Autolayout` 布局【`Xib`、`StoryBoard`、`Masonry` 、`SnapKit`、`SDAutoLayout` ...】的 `UITableViewCell` 和 `UITableViewHeaderFooterView` 的高度，支持横竖屏，内部自动管理高度缓存，已兼容 Swift 。

## Installation with  CocoaPods


```ruby
pod 'UITableViewDynamicLayoutCacheHeight'
pod install
#import <UITableViewDynamicLayoutCacheHeight/UITableViewDynamicLayoutCacheHeight.h>
```

- 如果只想使用免注册获取 Cell 和 UITableViewHeaderFooterView 可使用如下的 pod

```ruby
pod 'UITableViewDynamicLayoutCacheHeight/Category'
```

## Installation with Carthage
Carthage is a decentralized dependency manager that builds your dependencies and provides you with binary frameworks. To integrate UITableViewDynamicLayoutCacheHeight, add the following to your Cartfile.

```ruby
github "liangdahong/UITableViewDynamicLayoutCacheHeight" ~> 5.2.0
```

##  手动安装

- 下载项目 【 `clone https://github.com/liangdahong/UITableViewDynamicLayoutCacheHeight.git` 】
- 将 `UITableViewDynamicLayoutCacheHeight`  文件夹下的全部内容拖拽到你的项目。

## 图文使用说明

### `Cell` 使用 `Xib` 构建 「 也支持纯代码布局，只要是使用 **Autolayout** 均可 」

- 创建你的 Cell 且使用约束布局， 保证【 Cell 中的 View 从上向下布局，最底部的 View 的 MaxY 刚好是 Cell 所需高度即可】【不要设置底部约束限制，从上向下布局即可，内部会自动去获取最底部的 View 然后把它的 MaxY 做为 Cell 所需的高度 在 [代码 144~167 行 可查看获取过程](https://github.com/liangdahong/UITableViewDynamicLayoutCacheHeight/blob/master/UITableViewDynamicLayoutCacheHeight/Classes/UITableView%2BBMDynamicLayout.m)，然后做各种缓存操作 】 


![](Images/xib-cell-01.png)

- 在 UITableView 获取高度的代理方法里实现如下代码，Block 中的代码和 `- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath`  中的代码一致即可。

![](Images/xib-cell-02.png)

- 现在你的 `UITableView`  已经`自动算高`且`自动缓存高度`了，效果如下：

<img  width="22%" src="https://user-images.githubusercontent.com/12118567/89103687-3cbc6400-d446-11ea-9b66-cc349f7b8da4.gif"/>

- [ Swift Xib Demo ](https://github.com/liangdahong/UITableViewDynamicLayoutCacheHeight/tree/master/Example/Example/Classes/Swift/Xib)

-  [ Swift 纯代码布局 Demo ](https://github.com/liangdahong/UITableViewDynamicLayoutCacheHeight/tree/master/Example/Example/Classes/Swift/%E7%BA%AF%E4%BB%A3%E7%A0%81)

- 更多使用请参考 [ UITableView+BMDynamicLayout.h ](https://github.com/liangdahong/UITableViewDynamicLayoutCacheHeight/blob/master/UITableViewDynamicLayoutCacheHeight/Classes/UITableView%2BBMDynamicLayout.h) 文件的 API。

## 框架实现原理

### 高度计算原理

提前创建 Cell，然后填充内容，然后强制布局，然后获取 Cell 中 MaxY 最大的 View，然后取此 View 的 MaxY 为 Cell 所需高度【所以`保证 Cell 中的 View 的 MaxY 最大的值即为 Cell 需要的高度`至关重要】，内部会自动管理缓存的保存和清空操作。

## 问题

- 系统自动算高的缺陷大家应该都比较清楚，如：没缓存，重复计算，界面跳动，由于是边滚边算在布局复杂的 Cell 有一些问题，只支持iOS8+，布局必须要填充整个 Cell，在布局的时候一些场景需要设置优先，不然会报约束冲突。

- [UITableView-FDTemplateLayoutCell](https://github.com/forkingdog/UITableView-FDTemplateLayoutCell) 最开始我使用是此框架，同时 API 设计也参考自 FDTemplateLayoutCell，还用了几张素材，😁，在此感谢了 ，但后面有一些 Bug 一直没处理 😭，布局必须要填充整个 Cell，在布局的时候一些场景需要设置优先级，不然会报约束冲突，就迁移到了 [UITableViewDynamicLayoutCacheHeight](https://github.com/liangdahong/UITableViewDynamicLayoutCacheHeight)。

- [UITableViewDynamicLayoutCacheHeight](https://github.com/liangdahong/UITableViewDynamicLayoutCacheHeight) 的缺陷有，
- - ① 可能会多加一个 View【可以在计算的结果上加上底部距离，不建议这样处理】
- - ② 配置 Cell 的代码要在 2 个地方写，和 [UITableView-FDTemplateLayoutCell](https://github.com/forkingdog/UITableView-FDTemplateLayoutCell) 类似。

- 基于此框架实现了一个简陋的微信朋友圈功能 [微信朋友圈](https://github.com/liangdahong/UITableViewDynamicLayoutCacheHeight/tree/master/Example%E5%BE%AE%E4%BF%A1%E6%9C%8B%E5%8F%8B%E5%9C%88) 代码是几年前随便写的 😂，没准备调整了，感兴趣的可以瞧瞧。

## 常见问题处理

- 如果使用 key 做缓存，表示高度只和 key 有关，只要使用相同的 key 就会得到相同的高度，内部永远不会刷新这个高度「 即使调用了 reloadData 」。


## 联系
- 欢迎 [issues](https://github.com/liangdahong/UITableViewDynamicLayoutCacheHeight/issues) 和 [PR](https://github.com/liangdahong/UITableViewDynamicLayoutCacheHeight/pulls)
- 也可以添加微信<img width="20%" src="https://user-images.githubusercontent.com/12118567/86319172-72fb9d80-bc66-11ea-8c6e-8127f9e5535f.jpg"/> 进微信交流群。

## License    
[UITableViewDynamicLayoutCacheHeight](https://github.com/liangdahong/UITableViewDynamicLayoutCacheHeight) is released under the [MIT license](LICENSE). See LICENSE for details.
