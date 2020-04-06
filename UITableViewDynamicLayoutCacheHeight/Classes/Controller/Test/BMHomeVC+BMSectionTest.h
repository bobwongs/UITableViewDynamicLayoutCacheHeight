//
//  BMHomeVC+BMSectionTest.h
//  UITableViewDynamicLayoutCacheHeight
//
//  Created by mac on 2020/4/5.
//  Copyright © 2020 liangdahong. All rights reserved.
//

#import "BMHomeVC.h"

NS_ASSUME_NONNULL_BEGIN

@interface BMHomeVC (BMSectionTest)

- (void)insertSections;
- (void)deleteSections;
- (void)reloadSections;
- (void)moveSection;

@end

NS_ASSUME_NONNULL_END
