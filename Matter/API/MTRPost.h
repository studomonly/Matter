//
//  MTRPost.h
//  Matter
//
//  Created by Alex on 23/01/2015.
//  Copyright (c) 2015 DBHackathon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MTRDropboxLoader.h"

@protocol MTRPostChangeDelegate <NSObject>

@end

@interface MTRPost : NSObject

@property (nonatomic, readonly) NSString *title;
@property (nonatomic, readonly) NSString *body;
@property (nonatomic, readonly) NSDate *postDate;

- (instancetype)initWithTitle:(NSString *)title description:(NSString *)body images:(NSArray *)images;

- (instancetype)initWithDate:(NSDate *)date title:(NSString *)title description:(NSString *)body imageUrls:(NSArray *)imageUrls imageLoader:(MTRDropboxLoader *)loader;

- (NSArray *)retreiveImages;

- (void)retreiveImages:(void (^)(NSArray *))imageHandler;

- (void)listen:(id<MTRPostChangeDelegate>)delegate;

@end
