//
//  swypWorkspaceViewController.h
//  swyp
//
//  Created by Alexander List on 7/27/11.
//  Copyright 2011 ExoMachina. Some rights reserved -- see included 'license' file.
//

#import <Foundation/Foundation.h>
#import "swypContentInteractionManager.h"
#import "swypConnectionManager.h"
#import "swypSessionViewController.h"

@class swypWorkspaceViewController;
@protocol swypWorkspaceDelegate <NSObject>
-(void)	delegateShouldDismissSwypWorkspace: (swypWorkspaceViewController*)workspace;
@end

@interface swypWorkspaceViewController : UIViewController <swypConnectionManagerDelegate, UIGestureRecognizerDelegate> {
	swypContentInteractionManager *		_contentManager;
	swypConnectionManager *				_connectionManager;
	
	//*Dictionary of sessions to their views
	
	NSString *							_workspaceID;

	BOOL								_showContentWithoutConnection;
	
	id<swypWorkspaceDelegate>			_worspaceDelegate;
}

//if set to TRUE, then content is displayed before swyp connection is made, and if content is swyped, then connection + content transfer is made
@property (nonatomic, assign)	BOOL							showContentWithoutConnection;

@property (nonatomic, readonly)	NSString *						workspaceID;
@property (nonatomic, readonly)	swypConnectionManager*			connectionManager;
@property (nonatomic, readonly)	swypContentInteractionManager*	contentManager;

@property (nonatomic, assign)	id<swypWorkspaceDelegate>		worspaceDelegate;

-(id)	initWithContentWorkspaceID:(NSString*)workspaceID workspaceDelegate:(id<swypWorkspaceDelegate>)	worspaceDelegate;

@end
