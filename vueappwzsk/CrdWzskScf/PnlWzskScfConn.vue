<template>
	<v-card v-if=initdone class="pa-3 my-3 mx-auto" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="12">
					<div>{{tag.Cpt}}</div>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text>
		</v-card-text>
	</v-card>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzskScfConn',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWzskScfConn.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit('request', {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(consref) {
				const dpchapp = {
					"DpchAppWzskScfConnDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handlePupChange: function(cisref, fi) {
				this.contiac[cisref] = fi.num;

				this.updateEng(["contiac"]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWzskScfConn"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWzskScfConnData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWzskScfConnData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.StatShrWzskScfConn) this.statshr = dpcheng.StatShrWzskScfConn;
				if (dpcheng.TagWzskScfConn) {
					Wzsk.unescapeBlock(dpcheng.TagWzskScfConn);
					this.tag = dpcheng.TagWzskScfConn;
				};
				/*
				*/
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWzskVDpch, obj.dpcheng);
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWzskVDpch, dpcheng) {
				if (srefIxWzskVDpch == "DpchEngWzskScfConnData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzskVDpch == "DpchEngWzskScfConnData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
		},

		data: () => ({
			initdone: false,

			/*
			*/
			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
