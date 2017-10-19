Allows to have an exposed filter only show options that belong to result set.

To make it work:

[1] Enable the module.
[3] Add a field to the view that you want to use as a distinct field.
[3.2] Configure the field output in [3] as you wish.
[3.3] If you do not want this field to be shown in the result set,
just mark it as "Hide From Display".
[2] Add a filter of type "selective" to your view, and in the filter settings
select the field you configured in [3]. If the field is not showing, that means
that the filter and field you are trying to match are not compatible.

You can get 3 types of errors with this module:

(a) You did not properly match a filter and a field.
(b) You properly matched filter and field, but base field is not the same.
You get the same error text as in (a).
(c) You choose a field whose distinct value has more than the limit (100 by default) 
different possible values, obviously this field is not the kind of field you 
would use for a selective filter.
