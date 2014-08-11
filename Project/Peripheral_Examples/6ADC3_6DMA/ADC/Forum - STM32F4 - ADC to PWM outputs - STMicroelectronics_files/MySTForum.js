var s_lang = "en";
var s_accountID = $("meta[name='WT.z_user_mail']").attr('content');
var s_pName = "Extranet:" + $("meta[name='WT.z_portal_id']").attr('content') + ":Forum:" + document.title;
var s_siteType = $("meta[name='s_pName']").attr('content');
var s_company = $("meta[name='WT.z_user_comp']").attr('content');
var s_portalType = $("meta[name='WT.z_portal_type']").attr('content');
var s_forumName = $("Meta[name='WT.ti']").attr('content'); //Either on DefaultSite, DefaultSite/ForumSite, DefaultSite/ForumSite/Forum, DefaultSite/ForumSite/Forum/Post etc.
var s_forumType = $("Meta[name='ForumType']").attr('content'); 
var s_pState;

var DCS_dcsuri = document.URL.split("?")[0];

function ShowDiscussionsGrid(GridToShow) {
    if (GridToShow == 'MostRecent') {
        divMostRecent.style.display = 'block';
        btnMostRecent.className = "mystforum_active_tab";

        divMostViewed.style.display = 'none';
        btnMostViewed.className = "mystforum_inactive_tab";
        try {
            divMyDiscussions.style.display = 'none';
            btnMyDiscussions.className = "mystforum_inactive_tab";
        }
        catch (e) {
        }
    }
    else if (GridToShow == 'MostViewed') {
        divMostRecent.style.display = 'none';
        btnMostRecent.className = "mystforum_inactive_tab";

        divMostViewed.style.display = 'block';
        btnMostViewed.className = "mystforum_active_tab";

        try {
            divMyDiscussions.style.display = 'none';
            btnMyDiscussions.className = "mystforum_inactive_tab";
        }
        catch (e) {
        }
        LoadDiscussions('MostViewed', 'DIV_MostViewedDiscussions_WebPart');
    }
    else if (GridToShow == 'MyDiscussions') {
        divMostRecent.style.display = 'none';
        btnMostRecent.className = "mystforum_inactive_tab";

        divMostViewed.style.display = 'none';
        btnMostViewed.className = "mystforum_inactive_tab";
        try {
            divMyDiscussions.style.display = 'block';
            btnMyDiscussions.className = "mystforum_active_tab";
        }
        catch (e) {
        }
        LoadDiscussions('MyDiscussions', 'DIV_MyDiscussions_WebPart');
    }
    return false;
}


function UpdateDiscussions(discussions, context) {
    document.getElementById(context).innerHTML = discussions;
}

function ShowAjaxWebPartDivSection(divIDPrefix, sequenceNum) {
    var commonPrefixSelector = "div[id^='" + divIDPrefix + "']";
    var divSelector = "div[id^='" + divIDPrefix + sequenceNum + "']";
    $(commonPrefixSelector).hide();
    $(divSelector).show();
}
