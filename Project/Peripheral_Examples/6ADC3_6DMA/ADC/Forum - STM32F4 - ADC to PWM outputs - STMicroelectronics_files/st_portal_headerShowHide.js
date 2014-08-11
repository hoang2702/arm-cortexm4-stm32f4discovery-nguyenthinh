var breadcrumbsName;
$(document).ready(function() {
    var pathname = window.location.pathname;
    
    $("ul#nav li a").each(function() {
        var navHref = $(this).attr("href");
        if (pathname == navHref) {
            $("#nav li:first").removeClass();
            $(this).parent().attr("class", "active");
        }
    });
    try {

        var setHeaderWidth = ["myspace", "mycontacts"];

        for (var i = 0; i < setHeaderWidth.length; i++) {
            var string1 = setHeaderWidth[i].toUpperCase();

            pathname = pathname.toUpperCase();

            if (pathname.indexOf(string1) != -1) {

                $(".centralHeader").attr("style", "width:1024px;margin:auto");
                $("#divWrapper table:first").attr("style", "width:1024px;margin:auto");
            }
        }
        var urlParts = document.location.href.split('/');
        var serverurl = urlParts[0] + '//' + urlParts[2];
        var d = new Date();
        var url = serverurl + "/st-extranet-web-active/active/en/images/none.gif?ver=" + d.getTime();
        document.getElementById("wcms_image").src = url;
    }
    catch (e)

{ }

    var divLogin = "";
    try {
        divLogin = $.trim(document.getElementById('divLogin').innerHTML);
    }
    catch (e)
    { }
    if (divLogin.length != 0) {
        var strServerdate = document.getElementById('divPreviousLoginDate').innerHTML;
        strServerdate = $.trim(strServerdate);
        try {
            var arrDate = strServerdate.split(" ");
            var str_dd = arrDate[0];
            var str_MMM = arrDate[1];
            var str_yyyy = arrDate[2];
            var str_hmmss = arrDate[3];
            var str_tt = arrDate[4];
            var arrTime = str_hmmss.split(":");
            var str_hr = arrTime[0];
            var str_min = arrTime[1];
            var str_sec = arrTime[2];
            if (str_tt == "PM") str_hr = str_hr * 1 + 12;
            if (str_hr == 24) { str_hr = str_hr * 1 - 12; }

            var int_MMM = 0;
            if (str_MMM == "Jan") int_MMM = 0;
            else if (str_MMM == "Feb") int_MMM = 1;
            else if (str_MMM == "Mar") int_MMM = 2;
            else if (str_MMM == "Apr") int_MMM = 3;
            else if (str_MMM == "May") int_MMM = 4;
            else if (str_MMM == "Jun") int_MMM = 5;
            else if (str_MMM == "Jul") int_MMM = 6;
            else if (str_MMM == "Aug") int_MMM = 7;
            else if (str_MMM == "Sep") int_MMM = 8;
            else if (str_MMM == "Oct") int_MMM = 9;
            else if (str_MMM == "Nov") int_MMM = 10;
            else if (str_MMM == "Dec") int_MMM = 11;

            var dayLightSaving_GMTdiff = 2;
            if (int_MMM == 0 || int_MMM == 1 || int_MMM == 10 || int_MMM == 11) dayLightSaving_GMTdiff = 1;

            var clientOffset = (new Date().getTimezoneOffset()) * -1;
            var serverOffset = dayLightSaving_GMTdiff * 60 * 60 * 1000;
            var serverdate = new Date(str_yyyy, int_MMM, str_dd, str_hr, str_min, str_sec, 0);
            var clientdate = new Date();

            clientdate.setTime(serverdate.getTime() + (clientOffset * 60 * 1000) - serverOffset);

            var arrMonths = "Jan,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec";
            var str_secs = clientdate.getSeconds();
            var str_mins = clientdate.getMinutes();
            var str_hrs = clientdate.getHours();
            var str_date = clientdate.getDate();
            var str_month = arrMonths.split(",")[clientdate.getMonth()];
            var str_year = clientdate.getFullYear();

            if (str_secs < 10) str_secs = "0" + str_secs;
            if (str_mins < 10) str_mins = "0" + str_mins;
            if (str_hrs < 10) str_hrs = "0" + str_hrs;
            if (str_date < 10) str_date = "0" + str_date;

            var strClientDate = str_date + " " + str_month + " " + str_year + " " + str_hrs + ":" + str_mins + ":" + str_secs;
        }
        catch (ex) {
            strClientDate = strServerdate;
        }

        document.getElementById('divPreviousLoginDate').innerHTML = " Last connection date: <span class='italic'>" + strClientDate + "</span>";
    }
    try {
        var urlCheck = $("#hdnURLCheck").val();

        urlCheck = urlCheck.toUpperCase();
        urlCheck = urlCheck.split(',');
        pathname = pathname.toUpperCase();
        for (var i = 0; i < urlCheck.length; i++) {
            if (pathname.indexOf(urlCheck[i]) != -1) {
                $('#nav').animDropdown({
                    hoverClass: 'hover',
                    dropClass: 'drop-active',
                    items: '> li',
                    drop: '> .drop',
                    delay: 100,
                    animSpeed: 300,
                    effect: 'fade'
                });
            }
        }
    }
    catch (e)
    { }



    if ($(".ms-sbLastcell").text().length == 0) {
        $(".ms-sbLastcell").removeClass();
    }
    if (!$.browser.msie) {
        $("td.ms-sbcell").attr("style", "border:none");
    }
    $(".ms-sbrow .ms-sbgo img").attr("src", "/_layouts/images/st/portals/btn-submit.gif");
    $(".ms-sbrow .ms-sbgo img").attr("onmouseover", "this.src='/_layouts/images/st/portals/btn-submit.gif'");
    $(".ms-sbrow .ms-sbgo img").attr("onmouseout", "this.src='/_layouts/images/st/portals/btn-submit.gif'");
    $(".ms-sbrow .ms-sbgo img").attr("style", "border-radius: 0 13px 13px 0;");

    $("td.ms-sbcell").attr("style", "border:none");
    if ($.browser.msie) {
        $("td.ms-sbcell input[type=text]").attr("style", "width:178px;height:19px;");
        $("td.ms-sbcell input[type=text]").removeClass();
    }
    else {
        $("td.ms-sbcell input[type=text]").attr("style", "width:178px;");
        $(".ms-sbrow .ms-sbgo img").attr("style", "border-radius: 0 13px 13px 0");
        $("td.ms-sbcell input[type=text]").removeClass();
    }
    var setMargin = $("#Sub_breadcrumbs .breadcrumbs a").text().toUpperCase();
    if (setMargin.length > 0) {
        setMargin = $.trim(setMargin);
        if (setMargin == "HOME") {
            if (!$.browser.msie) {
                $(".header-c").attr("style", "padding-top:10px;padding-bottom:10px");

            }
            else {
                $(".header-c").attr("style", "padding-bottom:10px");
            }
        }
    }

    if ($("#hdnAppName").length > 0) {
        var appname = $("#hdnAppName").val();
        breadcrumbsName = appname;
        if (appname.length != 0) {
            $("#Sub_breadcrumbs .breadcrumbs li:last ").after(appname);
        }
    }
    $("#nav a ").click(function() {

        var navclass = $(this).text();
        if (navclass != "Home" && navclass != "MyST Home") {
            var leftNavsub_link = "<li>" + navclass + " </li>";
            $('#Sub_breadcrumbs .breadcrumbs  li:not(:first)').remove();
            $("#Sub_breadcrumbs .breadcrumbs li:nth-child(1)").after(leftNavsub_link);
        }
        else {
            $('#Sub_breadcrumbs .breadcrumbs  li:not(:first)').remove();
        }
    });
    $("#nav a").click(function(event) {
        var findclass = $(this).parent("li").attr("class");
        if (findclass == "hover drop-active") {
            $(this).attr("href", "#");
            $('#Sub_breadcrumbs .breadcrumbs  li:not(:first)').remove();
            $("#Sub_breadcrumbs .breadcrumbs li:nth-child(1)").after(breadcrumbsName);
            event.preventDefault();

        }
    });
});
// drop

(function($) {
    $.fn.animDropdown = function(o) {
        // default options
        var options = $.extend({
            hoverClass: 'hover',
            dropClass: 'drop-active',
            items: 'li',
            drop: '>ul',
            delay: 100,
            animSpeed: 300,
            effect: 'fade'
        }, o);

        return this.each(function() {
            // options
            var nav = $(this);
            items = nav.find(options.items);

            items.addClass(options.hoverClass).each(function() {
                var item = $(this), delayTimer;
                var drop = item.find(options.drop);
                item.data('drop', drop);
                if (drop.length) {
                    dropdownEffects[options.effect].prepare({ item: item, drop: drop });
                }

                item.bind('mouseenter', function() {
                    hideAllDropdowns(item);
                    item.addClass(options.hoverClass);
                    clearTimeout(delayTimer);
                    delayTimer = setTimeout(function() {
                        if (drop.length && item.hasClass(options.hoverClass)) {
                            item.addClass(options.dropClass);
                            dropdownEffects[options.effect].animate({ drop: drop, state: true, speed: options.animSpeed, complete: function() {
                                // callback
                            }
                            });
                        }
                    }, options.delay);
                    item.data('timer', delayTimer);
                }).bind('mouseleave', function() {
                    if (!item.hasClass(options.dropClass)) {
                        item.removeClass(options.hoverClass);
                    }
                    clearTimeout(delayTimer);
                    delayTimer = setTimeout(function() {
                        if (drop.length && item.hasClass(options.dropClass)) {
                            dropdownEffects[options.effect].animate({ drop: drop, state: false, speed: options.animSpeed, complete: function() {
                                // callback
                                item.removeClass(options.hoverClass);
                                item.removeClass(options.dropClass);
                            }
                            });
                        }
                    }, options.delay);
                    item.data('timer', delayTimer);
                });
            });

            // hide dropdowns
            items.removeClass(options.hoverClass);
            if (dropdownEffects[options.effect].postProcess) {
                items.each(function() {
                    dropdownEffects[options.effect].postProcess({ item: $(this) });
                });
            }

            // hide current level dropdowns
            function hideAllDropdowns(except) {
                var siblings = except.siblings();
                siblings.removeClass(options.hoverClass).each(function() {
                    var item = $(this);
                    clearTimeout(item.data('timer'));
                });
                siblings.filter('.' + options.dropClass).each(function() {
                    var item = jQuery(this).removeClass(options.dropClass);
                    if (item.data('drop').length) {
                        dropdownEffects[options.effect].animate({ drop: item.data('drop'), state: false, speed: options.animSpeed });
                    }
                });
            }
        });
    }

    // dropdown effects
    var dropdownEffects = {
        fade: {
            prepare: function(o) {
                o.drop.css({ opacity: 0, display: 'none' });
            },
            animate: function(o) {
                o.drop.stop().show().animate({ opacity: o.state ? 1 : 0 }, { duration: o.speed || 0, complete: function() {
                    if (o.state) {
                        o.drop.css({ opacity: '' });
                    } else {
                        o.drop.css({ opacity: 0, display: 'none' });
                    }
                    if (typeof o.complete === 'function') {
                        o.complete.call(o.drop);
                    }
                }
                });
            }
        },
        slide: {
            prepare: function(o) {
                var elementHeight = o.drop.show().outerHeight(true);
                var elementWidth = o.drop.show().outerWidth(true);
                var elementWrap = o.drop.wrap('<div class="drop-slide-wrapper">').parent();
                elementWrap.css({
                    height: elementHeight,
                    width: elementWidth,
                    position: 'absolute',
                    overflow: 'hidden',
                    top: o.drop.css('top'),
                    left: o.drop.css('left')
                });
                o.drop.css({
                    position: 'static',
                    display: 'block',
                    top: 'auto',
                    left: 'auto'
                });
                o.drop.data('height', elementHeight).data('wrap', elementWrap).css({ marginTop: -elementHeight });
            },
            animate: function(o) {
                o.drop.data('wrap').show().css({ overflow: 'hidden' });
                o.drop.stop().animate({ marginTop: o.state ? 0 : -o.drop.data('height') }, { duration: o.speed || 0, complete: function() {
                    if (o.state) {
                        o.drop.css({ marginTop: '' });
                        o.drop.data('wrap').css({ overflow: '' });
                    } else {
                        o.drop.data('wrap').css({ display: 'none' });
                    }
                    if (typeof o.complete === 'function') {
                        o.complete.call(o.drop);
                    }
                }
                });
            },
            postProcess: function(o) {
                if (o.item.data('drop').length) {
                    o.item.data('drop').data('wrap').css({ display: 'none' });
                }
            }
        }
    }
} (jQuery));


// Keyword search
function Header_keyword_focus() {
    if (document.getElementById('header_Search').value == 'Search') {
        document.getElementById('header_Search').value = '';
        //document.getElementById('header_Search').style.color = '#028ac8';
    }
}

function Header_keyword_blur() {
    if (document.getElementById('header_Search').value == '') {
        document.getElementById('header_Search').value = 'Search';
        //document.getElementById('header_Search').style.color = '#666666';
    }
}

function Header_EnterPress(e) {
    if (e) {
        e = e
    }
    else {
        e = window.event
    }

    if (e.which) {
        var keycode = e.which
    }
    else {
        var keycode = e.keyCode
    }

    if (keycode == 13) {
        if (document.getElementById('header_Search').value == '' || document.getElementById('header_Search').value == 'Search') {
            alert('Please specify a search criteria');
            return;
        }
        else {
            searchSelectionRadioButton();
            if (searchType == 'partNumberKeyword') {
                var urlParts = document.location.href.split('/');
                var serverurl = urlParts[0] + '//' + urlParts[2];
                var url = serverurl + "/st-extranet-web-active/active/en/search/partNumberKeyword"
                posturl(url, document.getElementById('header_Search').value, searchType, "POST");
            }
            else {
                var urlParts = document.location.href.split('/');
                var serverurl = urlParts[0] + '//' + urlParts[2];
                var url = serverurl + "/st-extranet-web-active/active/en/search/crossRef"
                posturl(url, document.getElementById('header_Search').value, searchType, "POST");
            }
        }
    }
}

function Header_EnterPress_anonymous(e) {
    if (e) {
        e = e
    }
    else {
        e = window.event
    }

    if (e.which) {
        var keycode = e.which
    }
    else {
        var keycode = e.keyCode
    }

    if (keycode == 13) {
        if (document.getElementById('header_Search').value == '' || document.getElementById('header_Search').value == 'Search') {
            alert('Please specify a search criteria');
            return;
        }
        else {
            searchSelectionRadioButton();
            var urlParts = document.location.href.split('/');
            var serverurl = urlParts[0] + '//' + urlParts[2];
            var url = serverurl + "/web/en/search/" + searchType;
            if (document.location.href.toLowerCase().match("qa-")) {
                url = "http://qa-www.st.com/web/en/search/" + searchType;
            }
            else {
                url = "http://www.st.com/web/en/search/" + searchType;
            }

            //var url = serverurl + "/web/en/search/" + searchType;
            posturl(url, document.getElementById('header_Search').value, searchType, "POST");
        }
    }
}


var searchType = "";
function searchSelectionRadioButton() {
    var radios = document.getElementsByName('searchType');
    for (var i = 0; i < radios.length; i++) {
        if (radios[i].type === 'radio' && radios[i].checked) {
            searchType = radios[i].value;
            break;
        }
    }
}
function handleSession() {
    try {
        top.handleYourSession();
    }
    catch (e)
    { }
}

function encodeVal(value1) {
    var tempValue = escape(value1);
    tempValue = tempValue.replace(/\//g, "%2F");
    tempValue = tempValue.replace(/\?/g, "%3F");
    tempValue = tempValue.replace(/=/g, "%3D");
    tempValue = tempValue.replace(/&/g, "%26");
    tempValue = tempValue.replace(/@/g, "%40");
    return tempValue;
}


function posturl(path, value1, searchTypeMethod, method) {

    value1 = encodeVal(value1);
    var form1 = document.createElement("form");
    form1.setAttribute("method", method);
    form1.setAttribute("action", path);

    var hiddenField = document.createElement("input");
    hiddenField.setAttribute("type", "hidden");
    hiddenField.setAttribute("name", "searchKeyUser");
    hiddenField.setAttribute("value", value1);
    form1.appendChild(hiddenField);

    hiddenField = document.createElement("input");
    hiddenField.setAttribute("type", "hidden");
    hiddenField.setAttribute("name", "searchKey");
    hiddenField.setAttribute("value", value1);
    form1.appendChild(hiddenField);

    hiddenField = document.createElement("input");
    hiddenField.setAttribute("type", "hidden");
    hiddenField.setAttribute("name", "searchType");
    hiddenField.setAttribute("value", searchTypeMethod);
    form1.appendChild(hiddenField);

    var tempWinLoc = window.location.href.toLowerCase();

    if ((tempWinLoc.match("/shared/common/integration/anonymousheader.aspx")) || (tempWinLoc.match("/shared/common/pages/header.aspx"))) {
        form1.setAttribute("target", "_blank");
    }
    document.body.appendChild(form1);

    form1.submit();
    window.event.returnValue = false;
}

function submit_searchBox() {

    if (document.getElementById('header_Search').value == '' || document.getElementById('header_Search').value == 'Search') {
        alert('Please specify a search criteria');
        return;
    }
    else {
        searchSelectionRadioButton();
        if (searchType == 'partNumberKeyword') {
            var urlParts = document.location.href.split('/');
            var serverurl = urlParts[0] + '//' + urlParts[2];
            var url = serverurl + "/st-extranet-web-active/active/en/search/partNumberKeyword"
            posturl(url, document.getElementById('header_Search').value, searchType, "POST");
        }
        else {
            var urlParts = document.location.href.split('/');
            var serverurl = urlParts[0] + '//' + urlParts[2];
            var url = serverurl + "/st-extranet-web-active/active/en/search/crossRef"
            posturl(url, document.getElementById('header_Search').value, searchType, "POST");
        }
    }
}

function submit_searchBox_anonymous() {

    if (document.getElementById('header_Search').value == '' || document.getElementById('header_Search').value == 'Search') {
        alert('Please specify a search criteria');
        return;
    }
    else {
        searchSelectionRadioButton();
        var urlParts = document.location.href.split('/');
        var serverurl = urlParts[0] + '//' + urlParts[2];
        var url = serverurl + "/web/en/search/" + searchType;
        if (document.location.href.toLowerCase().match("qa-")) {
            url = "http://qa-www.st.com/web/en/search/" + searchType;
        }
        else {
            url = "http://www.st.com/web/en/search/" + searchType;
        }

        //var url = serverurl + "/web/en/search/" + searchType;
        posturl(url, document.getElementById('header_Search').value, searchType, "POST");
    }
}
